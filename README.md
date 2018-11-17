# Tempo-ios-sdk

[![CI Status](https://img.shields.io/travis/Javier Aragón/Tempo-ios-sdk.svg?style=flat)](https://travis-ci.org/Javier Aragón/Tempo-ios-sdk)
[![Version](https://img.shields.io/cocoapods/v/Tempo-ios-sdk.svg?style=flat)](https://cocoapods.org/pods/Tempo-ios-sdk)
[![License](https://img.shields.io/cocoapods/l/Tempo-ios-sdk.svg?style=flat)](https://cocoapods.org/pods/Tempo-ios-sdk)
[![Platform](https://img.shields.io/cocoapods/p/Tempo-ios-sdk.svg?style=flat)](https://cocoapods.org/pods/Tempo-ios-sdk)

## Installation

Tempo-ios-sdk is available through [CocoaPods]. To install
it, simply add the following line to your Podfile:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
source 'git@github.com:GeographicaGS/ios-specs.git'
pod 'Tempo-ios-sdk'
```
Add the following line to your Info.plist

```ruby
MGLMapboxAccessToken API_KEY
```

## Example

```ruby
import UIKit
import Tempo_ios_sdk

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        let mapView = UIMapView.init(frame: view.bounds)
        view.addSubview(mapView)
    }


}
```

## Author

Javier Aragón, javier.aragon@geographica.gs

## License

Tempo-ios-sdk is available under the MIT license. See the LICENSE file for more info.
