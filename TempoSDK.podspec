#
# Be sure to run `pod lib lint Tempo-ios-sdk.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |spec|
  spec.name         = 'TempoSDK'
  spec.version      = '0.1.1'
  spec.license      = 'MIT'
  spec.summary      = 'iOS library for indoor mapping.'
  spec.homepage     = 'https://github.com/GeographicaGS'
  spec.author       = { 'Jesús Victorio' => 'jesus.victorio@geographica.gs' }
  spec.source       = { :git => 'git@github.com:jesusgeographica/pruebaSDKObjC.git'}
  spec.source_files = 'TempoSDK/Classes/**/*'
  spec.requires_arc = true
  spec.frameworks = ['GLKit', 'CartoMobileSDK']
  spec.libraries = ['z', 'c++']
  spec.dependency 'CartoMobileSDK', '4.1.4'
  spec.xcconfig = {
    "FRAMEWORK_SEARCH_PATHS": "\"$(PODS_ROOT)/CartoMobileSDK/\""
  }

end
