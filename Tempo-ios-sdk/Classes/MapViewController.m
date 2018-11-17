//
//  MapViewController.m
//  Tempo-ios-sdk
//
//  Created by Jesus Victorio on 17/11/2018.
//  Copyright © 2018 Geographica. All rights reserved.
//

#import "MapViewController.h"

@interface MapViewController ()

@end

@implementation MapViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)initMap{
    NSString* License = @"XTUMwQ0ZRQ3VqQkgxQ3RSVjlLNlNSUmZFOXR0VDlWdzc3Z0lVWEZMQ1hIVis5Njc5Y1lYWHE1TXJOYXY2TEQ0PQoKYXBwVG9rZW49NzkwODczNmUtMmFmNS00YTg4LWI1NGItNGVmNWI1MzRlNjA5CmJ1bmRsZUlkZW50aWZpZXI9Y29tLmNhcnRvLmhlbGxvbWFwLm9iagpvbmxpbmVMaWNlbnNlPTEKcHJvZHVjdHM9c2RrLWlvcy00LioKd2F0ZXJtYXJrPWN1c3RvbQo=";
    
    // The initial step: register your license.
    // This must be done before using MapView
    [NTMapView registerLicense:License];
}

- (void)loadMap{
    NTMapView* mapView = (NTMapView*) self.view;
    
    // Add base layer
    NTVectorTileLayer* layer = [[NTCartoOnlineVectorTileLayer alloc] initWithStyle:NT_CARTO_BASEMAP_STYLE_VOYAGER];
    [[mapView getLayers] add:layer];
    
    NTProjection* proj = [[mapView getOptions] getBaseProjection];
    
    // Animate zoom to Tallinn, Estonia
    NTMapPos* tallinn = [proj fromWgs84:[[NTMapPos alloc] initWithX:24.646469 y:59.426939]];
    [mapView setZoom:3 durationSeconds:2];
    [mapView setFocusPos:tallinn durationSeconds:0];
    
    // Initialize a local vector data source
    NTLocalVectorDataSource* vectorDataSource = [[NTLocalVectorDataSource alloc] initWithProjection:proj];
    
    // Initialize a vector layer with the previous data source
    NTVectorLayer* vectorLayer = [[NTVectorLayer alloc] initWithDataSource:vectorDataSource];
    
    // Add the previous vector layer to the map
    [[mapView getLayers] add:vectorLayer];
}

@end
