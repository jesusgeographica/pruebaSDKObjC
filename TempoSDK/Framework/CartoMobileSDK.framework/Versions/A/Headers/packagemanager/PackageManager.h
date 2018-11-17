/*
 * Copyright (c) 2016 CartoDB. All rights reserved.
 * Copying and using this code is allowed only according
 * to license terms, as given in https://cartodb.com/terms/
 */

#ifndef _CARTO_PACKAGEMANAGER_H_
#define _CARTO_PACKAGEMANAGER_H_

#ifdef _CARTO_PACKAGEMANAGER_SUPPORT

#include "core/MapPos.h"
#include "core/MapBounds.h"
#include "core/MapTile.h"
#include "components/DirectorPtr.h"
#include "packagemanager/PackageInfo.h"
#include "packagemanager/PackageMetaInfo.h"
#include "packagemanager/PackageStatus.h"
#include "packagemanager/PackageTileMask.h"
#include "packagemanager/PackageManagerListener.h"
#include "utils/NetworkUtils.h"

#include <string>
#include <cstdint>
#include <vector>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <thread>

namespace sqlite3pp {
    class database;
    namespace ext {
        class function;
    }
}

namespace carto {
    class BinaryData;
    class Projection;
    class PackageHandler;

    /**
     * Base class for offline map package manager. Package manager supports downloading/removing packages.
     * It can be queried about available packages and status of the packages. It works asynchronously in
     * the background and can inform app when packages have been updated.
     * It works persistently. If a package download is started and app is closed, the download will resume
     * when the package manager is started next time.
     */
    class PackageManager {
    public:

        /**
         * Listener interface for package/style change events.
         */
        class OnChangeListener {
        public:
            virtual ~OnChangeListener() { }

            /**
             * Called when a package has been added, removed or updated.
             */
            virtual void onPackagesChanged() = 0;

            /**
             * Called when a style has been updated.
             */
            virtual void onStylesChanged() = 0;
        };

        /**
         * Constructs a new package manager, given URL for package list and data folder.
         * The data folder must exist before creating a new package manager and it is assumed to be persistent.
         * Note: the package manager must be explicitly started using start() method!
         * @param packageListURL The URL that defines all packages.
         * @param dataFolder The folder where downloaded packages are kept. It must exist and must be writable.
         * @param serverEncKey Encryption key for server packages
         * @param localEncKey Encryption key for local packages
         * @throws std::runtime_error If package manager fails to open or create package database.
         */
        PackageManager(const std::string& packageListURL, const std::string& dataFolder, const std::string& serverEncKey, const std::string& localEncKey);
        virtual ~PackageManager();

        /**
         * Returns the current listener for package manager events.
         * @return The current listener or null if none is set.
         */
        std::shared_ptr<PackageManagerListener> getPackageManagerListener() const;
        /**
         * Sets the package manager listener.
         * @param listener The new package manager listener to use.
         */
        void setPackageManagerListener(const std::shared_ptr<PackageManagerListener>& listener);

        /**
         * Registers listener for package data change events.
         * @param listener The listener for change events.
         */
        void registerOnChangeListener(const std::shared_ptr<OnChangeListener>& listener);
        /**
         * Unregisters listener from package data change events.
         * @param listener The previously added listener.
         */
        void unregisterOnChangeListener(const std::shared_ptr<OnChangeListener>& listener);

        /**
         * Starts the package manager. All previous tasks will be resumed after this.
         * @return True if package manager was successfully started. False otherwise (can not create/access database).
         */
        bool start();
        /**
         * Stops the package manager. The stopping can be asynchronous or synchronous.
         * @param wait If set to true, then synchronous stopping is performed and the operation may take a while.
         */
        void stop(bool wait);

        /**
         * Returns the current schema of the packages.
         * @return The current schema of the packages.
         */
        std::string getSchema() const;

        /**
         * Returns the list of available server packages.
         * Note that the list must be retrieved from the server first, using startPackageListDownload.
         * @return The list of available server packages.
         */
        std::vector<std::shared_ptr<PackageInfo> > getServerPackages() const;
        /**
         * Returns the list of available local downloaded packages.
         * @return The list of available local downloaded packages.
         */
        std::vector<std::shared_ptr<PackageInfo> > getLocalPackages() const;
        /**
         * Returns the metainfo of server packages.
         * @return The metainfo data about server packages, or null if no metainfo is available.
         */
        std::shared_ptr<PackageMetaInfo> getServerPackageListMetaInfo() const;
        /**
         * Returns the age of server package list. This method can be used to measure the time of the download and check whether the list should be updated.
         * @return The age of server package list in seconds.
         */
        int getServerPackageListAge() const;

        /**
         * Returns the specified server package.
         * Note that the list must be retrieved from the server first, using startPackageListDownload.
         * @param packageId The id of the package.
         * @return The specified server package or null if it is not in the server package list.
         */
        std::shared_ptr<PackageInfo> getServerPackage(const std::string& packageId) const;
        /**
         * Returns the specified local package.
         * @param packageId The id of the package.
         * @return The specified local package or null if it can not be found in the local package list. Note that if the package is being downloaded, null is returned.
         */
        std::shared_ptr<PackageInfo> getLocalPackage(const std::string& packageId) const;
        /**
         * Returns the status of the specified package.
         * @param packageId The id of the package.
         * @param version The version of the package. Use -1 for the latest version.
         * @return The status of the package or null if it is not yet downloaded. If the package is currently being downloaded, its status is returned.
         */
        std::shared_ptr<PackageStatus> getLocalPackageStatus(const std::string& packageId, int version) const;

        /**
         * Locks local packages and calls specified handler callback.
         * @param callback The callback function.
         */
        void accessLocalPackages(const std::function<void(const std::map<std::shared_ptr<PackageInfo>, std::shared_ptr<PackageHandler> >&)>& callback) const;

        /**
         * Suggests packages for given map position. Note that in order this to work, local package list must be available first.
         * @param mapPos The map position.
         * @param projection The projection for the map position.
         * @return The sorted list of suggested packages (from the best to the worst). The list may contain downloaded packages.
         */
        std::vector<std::shared_ptr<PackageInfo> > suggestPackages(const MapPos& mapPos, const std::shared_ptr<Projection>& projection) const;

        /**
         * Tests if the specified map area at specified zoom level is downloaded.
         * @param mapBounds The area bounding box.
         * @param zoom The zoom level to check.
         * @param projection The projection for the bounding box.
         * @return True if all required tiles are downloaded and available. False otherwise.
         */
        bool isAreaDownloaded(const MapBounds& mapBounds, int zoom, const std::shared_ptr<Projection>& projection) const;

        /**
         * Starts downloading package list asynchronously. When this task finishes, listener is called and server package list is updated.
         * @return True if the package list will be downloaded and listener will be notified (if set). False if it can not be downloaded.
         */
        bool startPackageListDownload();
        /**
         * Starts importing the specified package asynchronously. When this task finishes, listener is called and local package list is updated.
         * Note 1: In general, package manager may need temporary storage equal to the size of the package during import. It is the responsibility of the app to perform such checks.
         * Note 2: the package may not be deleted after this call, as the import is asynchronous operation. It is safe to delete the original file once import is complete (this is notified via manager listener).
         * @param packageId The id of the package to download.
         * @param version The version of the package.
         * @param packageFileName The fully qualified path of the package. The file name may also refer to URL or asset (using 'asset://' prefix).
         * @return True is the package will be imported.
         */
        bool startPackageImport(const std::string& packageId, int version, const std::string& packageFileName);
        /**
         * Starts downloading specified package asynchronously. When this task finishes, listener is called and local package list is updated.
         * Note: In general, package manager may need temporary storage equal to the size of the package during download. It is the responsibility of the app to perform such checks.
         * @param packageId The id of the package to download.
         * @return True is the package is available and will be downloaded. False if the package was not found.
         */
        bool startPackageDownload(const std::string& packageId);
        /**
         * Starts the removal of specified package asynchronously. When this task finishes, listener is called and local package list is updated.
         * @param packageId The id of the package to remove.
         * @return True is the package was found and will be removed. False if the package was not found.
         */
        bool startPackageRemove(const std::string& packageId);

        /**
         * Cancels the current/pending tasks involving of the specified package.
         * @param packageId The id of the package to cancel.
         */
        void cancelPackageTasks(const std::string& packageId);

        /**
         * Sets the priority of the specific package.
         * If the given priority is higher than priority of any other package, other operations will be paused and this package is processed immediately.
         * If the given priority is set to negative value, package download will be paused until priority is reset to non-negative value.
         * @param packageId The id of the download package.
         * @param priority The priority of the download package. If it is less than zero, package download is paused.
         */
        void setPackagePriority(const std::string& packageId, int priority);
        
    protected:
        /**
         * Starts downloading the specified style. When this task finishes, listener is called.
         * @param styleName The name of the style to download.
         * @return True if download process was started.
         */
        bool startStyleDownload(const std::string& styleName);

        virtual std::string createLocalFilePath(const std::string& name) const;
        virtual std::string createPackageFileName(const std::string& packageId, PackageType::PackageType packageType, int version) const;
        virtual std::string createPackageListURL(const std::string& baseURL) const;
        virtual std::string createPackageURL(const std::string& packageId, int version, const std::string& baseURL, bool downloaded) const;
        
        virtual std::shared_ptr<PackageInfo> getCustomPackage(const std::string& packageId, int version) const;

        virtual bool updateStyle(const std::string& styleName);
        
        void notifyPackagesChanged();
        void notifyStylesChanged();

    private:
        struct Task {
            enum Command {
                NOP = 0,
                DOWNLOAD_PACKAGE_LIST = 1,
                DOWNLOAD_PACKAGE = 2,
                IMPORT_PACKAGE = 3,
                REMOVE_PACKAGE = 4,
                DOWNLOAD_STYLE = 5
            };

            Command command = NOP;
            int priority = 0;
            PackageAction::PackageAction action = PackageAction::PACKAGE_ACTION_WAITING;
            int progress = 0;
            std::string packageId;
            PackageType::PackageType packageType = PackageType::PACKAGE_TYPE_MAP;
            int packageVersion = 0;
            std::string packageLocation;
        };

        class PersistentTaskQueue {
        public:
            PersistentTaskQueue(const std::string& dbFileName);

            int getActiveTaskId(int currentActiveTaskId = -1) const;
            std::vector<int> getTaskIds() const;
            Task getTask(int taskId) const;

            int scheduleTask(const Task& task);
            bool isTaskCancelled(int taskId) const;
            void cancelTask(int taskId);
            void setTaskPriority(int taskId, int priority);
            void updateTaskStatus(int taskId, PackageAction::PackageAction action, float progress);
            void deleteTask(int taskId);

        private:
            std::shared_ptr<sqlite3pp::database> _localDb;
            mutable std::recursive_mutex _mutex;
        };

        struct PauseException : std::exception {
            PauseException() { }
        };

        struct CancelException : std::exception {
            CancelException() { }
        };
        
        struct PackageException : std::runtime_error {
            PackageException(PackageErrorType::PackageErrorType errorType, const std::string& msg) : runtime_error(msg), _errorType(errorType) { }
            PackageErrorType::PackageErrorType getErrorType() const { return _errorType; }
            
        private:
            PackageErrorType::PackageErrorType _errorType;
        };

        void run();

        bool downloadPackageList(int taskId);
        bool importPackage(int taskId);
        bool downloadPackage(int taskId);
        bool removePackage(int taskId);
        bool downloadStyle(int taskId);
        
        void syncLocalPackages();
        void importLocalPackage(int id, int taskId, const std::string& packageId, PackageType::PackageType packageType, const std::string& packageFileName);
        void deleteLocalPackage(int id);

        bool isTaskCancelled(int taskId) const;
        bool isTaskPaused(int taskId) const;
        void updateTaskStatus(int taskId, PackageAction::PackageAction action, float progress);
        void setTaskFinished(int taskId);
        void setTaskPaused(int taskId);
        void setTaskCancelled(int taskId);
        void setTaskFailed(int taskId, PackageErrorType::PackageErrorType errorType);

        std::string loadPackageListJson(const std::string& jsonFileName) const;
        void savePackageListJson(const std::string& jsonFileName, const std::string& json) const;

        static void InitializeDb(sqlite3pp::database& db, const std::string& encKey);
        static bool CheckDbEncryption(sqlite3pp::database& db, const std::string& encKey);
        static std::string CalculateKeyHash(const std::string& encKey);

        static MapTile CalculateMapTile(const MapPos& mapPos, int zoom, const std::shared_ptr<Projection>& proj);

        static std::shared_ptr<PackageTileMask> DecodeTileMask(const std::string& tileMaskStr);
        static std::string EncodeTileMask(const std::shared_ptr<PackageTileMask>& tileMask);

        static int DownloadFile(const std::string& url, NetworkUtils::HandlerFunc handler, std::uint64_t offset = 0);

        static const int DEFAULT_TILEMASK_ZOOMLEVEL;

        const std::string _packageListURL;
        const std::string _packageListFileName;
        const std::string _dataFolder;
        const std::string _serverEncKey;
        const std::string _localEncKey;

        std::vector<std::shared_ptr<PackageInfo> > _localPackages;
        std::shared_ptr<sqlite3pp::database> _localDb;
        std::shared_ptr<PersistentTaskQueue> _taskQueue;
        std::condition_variable_any _taskQueueCondition; // notified when new tasks are available
        std::shared_ptr<std::thread> _packageManagerThread;
        std::vector<std::shared_ptr<OnChangeListener> > _onChangeListeners;
        bool _stopped;

        int _prevTaskId;
        PackageAction::PackageAction _prevAction;
        int _prevRoundedProgress;

        ThreadSafeDirectorPtr<PackageManagerListener> _packageManagerListener;

        mutable std::shared_ptr<std::vector<std::shared_ptr<PackageInfo> > > _serverPackageCache;
        mutable std::map<std::shared_ptr<PackageInfo>, std::shared_ptr<PackageHandler> > _packageHandlerCache;

        mutable std::recursive_mutex _mutex; // guards all state
    };

}

#endif

#endif
