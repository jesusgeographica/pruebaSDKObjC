/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.11
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#import <Foundation/Foundation.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Possible image formats.
 */
typedef NS_ENUM(NSInteger, NTColorFormat) {
/**
 * Options for identifiny unsupported image formats.
 */
  NT_COLOR_FORMAT_UNSUPPORTED = 0,
/**
 * An image format that describes images with a single color channel.
 */
  NT_COLOR_FORMAT_GRAYSCALE = 0x1909,
/**
 * An image format that describes images with two channels, one for color and the other<br>
 * for alpha.
 */
  NT_COLOR_FORMAT_GRAYSCALE_ALPHA = 0x190A,
/**
 * An image format that describes images with three channels, one for each color: red, green and blue.
 */
  NT_COLOR_FORMAT_RGB = 0x1907,
/**
 * An image format that describes images with four channels, one for each color: red, green and blue<br>
 * and one for alpha.
 */
  NT_COLOR_FORMAT_RGBA = 0x1908,
/**
 * An image format that describes images with four channels, one for each color: blue, green and red<br>
 * and one for alpha. This color format will be converted to RGBA.
 */
  NT_COLOR_FORMAT_BGRA = 1,
/**
 * An image format that describes images with four channels, one for each color: red, green, and blue<br>
 * and one for alpha. Each color is only four bits. This color format will be converted to RGBA.
 */
  NT_COLOR_FORMAT_RGBA_4444 = 2,
/**
 * An image format that describes images with three channels, one for each color: red, green, and blue.<br>
 * Red and blue colors are each packed into 5 bits, green into 6 bits. This color format will be converted to RGB.
 */
  NT_COLOR_FORMAT_RGB_565 = 3
};


#import "NTBinaryData.h"

/**
 * A class that provides the functionality to store, compress, uncompress and resize basic image formats.<br>
 * Currently supported formats are png and jpeg. Upon loading compressed images will be converted to<br>
 * alpha premultiplied uncompressed bitmaps of various image formats.
 */
__attribute__ ((visibility("default"))) @interface NTBitmap : NSObject
{
  /** @internal:nodoc: */
  void *swigCPtr;
  /** @internal:nodoc: */
  BOOL swigCMemOwn;
}
/** @internal:nodoc: */
-(void*)getCptr;
/** @internal:nodoc: */
-(id)initWithCptr: (void*)cptr swigOwnCObject: (BOOL)ownCObject;

/**  
 * Checks if this object is equal to the specified object.
 * @param object The reference object.
 * @return True when objects are equal, false otherwise.
 */
-(BOOL)isEqual:(id)object;

/**
 * Returns the hash value of this object.
 * @return The hash value of this object.
 */
-(NSUInteger)hash;

/**
 * Constructs a bitmap from an already decoded vector of bytes. The bitmap data is expected to be alpha premultiplied, if alpha channel is used.<br>
 * If the power of two conversion flag is set, additional padding will be added to the image to make it's dimensions power of two.<br>
 * This can be useful when creating OpenGL textures from the Bitmap, because some GPUs perform badly with non power of two textures.<br>
 * @param pixelData A vector of decoded, premultiplied bitmap bytes.<br>
 * @param width The width of the bitmap.<br>
 * @param height The height of the bitmap.<br>
 * @param colorFormat The color format of the bitmap.<br>
 * @param bytesPerRow The total number of bytes per row. Some bitmaps have additional padding at the end of each row. If the value is negative, then bitmap is assumed to be vertically flipped. In this case absolute value of the bytesPerRow value is used.
 */
-(id)initWithPixelData: (NTBinaryData*)pixelData width: (unsigned int)width height: (unsigned int)height colorFormat: (enum NTColorFormat)colorFormat bytesPerRow: (int)bytesPerRow;
/**
 * Returns the width of the bitmap.<br>
 * @return The width of the bitmap.
 */
-(unsigned int)getWidth;
/**
 * Returns the height of the bitmap.<br>
 * @return The height of the bitmap.
 */
-(unsigned int)getHeight;
/**
 * Returns the color format of this bitmap.<br>
 * @return The color format of this bitmap.
 */
-(enum NTColorFormat)getColorFormat;
/**
 * Returns the bytes per pixel parameter of this bitmap. Valid values are 1, 2, 3 and 4.<br>
 * @return The bytes per pixel parameter of this bitmap.
 */
-(unsigned int)getBytesPerPixel;
/**
 * Returns a copy of the pixel data of this bitmap.<br>
 * @return A binary data of the bitmap's pixel data.
 */
-(NTBinaryData*)getPixelData;
/**
 * Compresses this bitmap to a png.<br>
 * @return A byte vector of the png's data.
 */
-(NTBinaryData*)compressToPng;
/**
 * Compresses this bitmap to a internal format.<br>
 * This operation is intended for serialization of the data only, no actual compression is performed.<br>
 * @return A byte vector of the serialized data.
 */
-(NTBinaryData*)compressToInternal;
/**
 * Returns resized version of the bitmap. The power of two padding added during the construction of this bitmap<br>
 * will be removed prior to resizing. If the power of two conversion flag is set, new padding will be added to the image <br>
 * after resizing to make it's dimensions power of two.<br>
 * @param width The new width of this bitmap.<br>
 * @param height The new height of this bitmap.<br>
 * @return The resized bitmap instance or null in case of error (wrong dimensions).
 */
-(NTBitmap*)getResizedBitmap: (unsigned int)width height: (unsigned int)height;
/**
 * Returns sub-bitmap with specified offsets and dimensions.<br>
 * @param xOffset X coordinate offset in the bitmap.<br>
 * @param yOffset Y coordinate offset in the bitmap.<br>
 * @param width Width of the sub-bitmap.<br>
 * @param height Height of the sub-bitmap.<br>
 * @return Sub-bitmap instance or null in case of error (wrong dimensions).
 */
-(NTBitmap*)getSubBitmap: (int)xOffset yOffset: (int)yOffset width: (int)width height: (int)height;
/**
 * Returns paddedsub-bitmap with specified offsets and dimensions.<br>
 * @param xPadding Padding along X coordinate. If negative value is used, the bitmap is padded from the left. By default, bitmap is padded from the right.<br>
 * @param yPadding Padding along Y coordinate. If negative value is used, the bitmap is padded from the top. By default, bitmap is padded from the bottom.<br>
 * @return Padded bitmap instance or null in case of error (wrong dimensions).
 */
-(NTBitmap*)getPaddedBitmap: (int)xPadding yPadding: (int)yPadding;
/**
 * Returns copy of the bitmap converted to RGBA format.<br>
 * @return The bitmap with identical dimensions but converted to RGBA format.
 */
-(NTBitmap*)getRGBABitmap;
/**
 * Creates a new bitmap from compressed byte vector.<br>
 * If the power of two conversion flag is set, additional padding will be added to the image to make it's dimensions power of two.<br>
 * @param compressedData The compressed bitmap data.<br>
 * @return The bitmap created from the compressed data. If the decompression fails, null is returned.
 */
+(NTBitmap*)createFromCompressed: (NTBinaryData*)compressedData;
/**
 * Returns the raw pointer to the object. This is used internally by the SDK.<br>
 * @return The internal pointer of the object.
 */
/** @internal:nodoc: */
-(long long)swigGetRawPtr;

-(void)dealloc;

@end


#ifdef __cplusplus
}
#endif

