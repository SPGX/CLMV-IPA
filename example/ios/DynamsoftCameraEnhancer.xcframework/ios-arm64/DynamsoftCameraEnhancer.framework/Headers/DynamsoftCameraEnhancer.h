//
//  Dynamsoft Camera Enhancer SDK
//
//  Copyright © 2021 Dynamsoft. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

#import <DynamsoftCameraEnhancer/DCEBase.h>
#import <DynamsoftCameraEnhancer/DCECameraView.h>
#import <DynamsoftCameraEnhancer/DCEDrawingLayer.h>
#import <DynamsoftCameraEnhancer/DCEImageEditorView.h>
#import <DynamsoftCameraEnhancer/DrawingStyleManager.h>
#import <DynamsoftCameraEnhancer/DrawingStyle.h>
#import <DynamsoftCameraEnhancer/DrawingItem.h>
#import <DynamsoftCameraEnhancer/RectDrawingItem.h>
#import <DynamsoftCameraEnhancer/QuadDrawingItem.h>
#import <DynamsoftCameraEnhancer/TextDrawingItem.h>

NS_ASSUME_NONNULL_BEGIN

@class iRegionDefinition;

/**
* DynamsoftCameraEnhancer is the class that provides camera control APIs.
*/
@interface DynamsoftCameraEnhancer:NSObject<ImageSource>

/**
 * The property that controls whether to display the scan region on the UI.
 *       scanRegionVisible = true: The scan region will be displayed on the UI.
 *       scanRegionVisible = false: The scan region will not be displayed.
*/
@property (nonatomic, assign) BOOL scanRegionVisible;

@property (nonatomic, strong) DCECameraView *dceCameraView;

/**
 * Initialize the camera enhancer with the camera view.
 *
 * @param [in] view An instance of the DCECameraView.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
 * @endcode
*/
- (instancetype)initWithView:(DCECameraView *)view NS_SWIFT_NAME(init(view:));

/**
 * Initialize the license for Dynamsoft Camera Enhancer.
 *
 * @param [in] license A license key. It can be online/offline, trial/full.
 * @param [in,out] connectionDelegate The license verification callback.
 *
 * @par Code Snippet:
 * @code
     [DynamsoftCameraEnhancer initLicense:@"Put your license here." verificationDelegate:self];
 * @endcode
*/
+ (void)initLicense:(NSString*)license verificationDelegate:(id)connectionDelegate DEPRECATED_MSG_ATTRIBUTE("Will be removed in feature.");

/**
 * Get the current SDK version.
 * 
 * @return The current SDK version.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
     
     NSString* version = [cameraEnhancer getVersion];
 * @endcode
*/
+ (NSString*)getVersion;

/**
 * Get the camera state (Opening, Opened, Closing, closed).
 * 
 * @return The current camera state.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
     
     EnumCameraState state = [cameraEnhancer getCameraState];
 * @endcode
*/
- (EnumCameraState)getCameraState;

/**
 * Enable advanced features of Dynamsoft Camera Enhancer with one or more EnumEnhancerFeature candidates.
 *
 * @param [in] enumEnhancerFeatures A combined value of EnumEnhancerFeatures. It refers to the features that you want to enable.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
     
     [cameraEnhancer enableFeatures:0x01 error: &error];
 * @endcode
*/
- (BOOL)enableFeatures:(NSInteger)enumEnhancerFeatures error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(enableFeatures(_:));

/**
 * Disable the specified features.
 *
 * @param [in] enumEnhancerFeatures A combined value of EnumEnhancerFeatures. It refers to the features that you want to disable.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
     
     [cameraEnhancer disableFeatures:0x02];
 * @endcode
*/
- (void)disableFeatures:(NSInteger)enumEnhancerFeatures;

/**
 * Check whether the input features are enabled.
 *
 * @return Whether all the input features are all enabled.
 *         true: All the input features are enabled.
 *         false: Not all the input features are enabled.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
     
     BOOL featureEnabled = [_dce isFeatureEnabled:0x02];
 * @endcode
*/
- (BOOL)isFeatureEnabled:(NSInteger)enumEnhancerFeatures;

/**
 * Get the latest video frame from the video buffer.
 *
 * @param [in] iskeep If true, the frame in the video buffer will be kept. Otherwise, the frame will be removed from video buffer when you have got it.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
     
     DCEFrame *dceFrame = [cameraEnhancer getFrameFromBuffer:true];
 * @endcode
*/
- (DCEFrame*)getFrameFromBuffer:(BOOL)iskeep;

/**
 * Resume the camera.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
     
     [cameraEnhancer resume];
 * @endcode
*/
- (void)resume NS_SWIFT_NAME(resume());

/**
 * Pause the camera
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
     
     [cameraEnhancer pause];
 * @endcode
*/
- (void)pause NS_SWIFT_NAME(pause());

/**
 * Add a listener.
 *
 * @param [in] listener The listener ID.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     [cameraEnhancer addListener:self];
 * @endcode
*/
- (void)addListener:(nonnull id<DCEFrameListener>)listener NS_SWIFT_NAME(addListener(_:));

/**
 * Remove a listener
 *
 * @param [in] listener The listener ID.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     [cameraEnhancer removeListener:self];
 * @endcode
*/
- (void)removeListener:(nonnull id<DCEFrameListener>)listener NS_SWIFT_NAME(removeListener(_:));

/**
 * Turn on the torch.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     [cameraEnhancer turnOnTorch];
 * @endcode
*/
- (void)turnOnTorch;

/**
 * Turn off the torch.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     [cameraEnhancer turnOffTorch];
 * @endcode
*/
- (void)turnOffTorch;

/**
 * Set zoom factor. The camera will zoom-in(out) immediately when the method is triggered.
 *
 * @param [in] factor A float value that refers to the zoom factor.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     [cameraEnhancer setZoom:3.5f];
 * @endcode
*/
- (void)setZoom:(CGFloat)factor;

/**
 * Get the current frame rate.
 *
 * @return An int value that refers to the current frame rate.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     int frameRate = [cameraEnhancer getFrameRate];
 * @endcode
*/
- (int)getFrameRate;

/**
 * Set a focus position to trigger a focus immediately.
 *
 * @param [in] point A CGPoint that determines the receiver's focus point of interest, if it has one. A value of (0,0) indicates that the camera should focus on the top left corner of the image, while a value of (1,1) indicates that it should focus on the bottom right. The default value is (0.5,0.5).
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     CGPoint focusPoint = {0.4, 0.5};
     [cameraEnhancer setFocus:focusPoint];
 * @endcode
*/
- (void)setFocus:(CGPoint)point NS_SWIFT_NAME(setFocus(_:));

/**
 * Get the IDs of all available cameras.
 * 
 * @return A NSArray that contains the IDs of all available cameras.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     NSArray<NSString*>* allCameras = [_dce getAllCameras];
 * @endcode
*/
- (NSArray<NSString*>*)getAllCameras;

/**
 * Select a camera with the camera ID.
 *
 * @param [in] cameraId An iRegionDefinition value that refers to the scan region setting.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     NSError *error = [[NSError alloc] init];
     [cameraEnhancer selectCamera:@"BACK_FACING_CAMERA" error: &error];
 * @endcode
*/
- (BOOL)selectCamera:(NSString*)cameraId error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(selectCamera(_:));

/**
 * Get the ID of the selected camera.
 * 
 * @return A NSString that refers to the current selected camera.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     NSString* selectedCamera = [cameraEnhancer getSelectedCamera];
 * @endcode
*/
- (NSString*)getSelectedCamera;

/**
 * Specify the resolution. The default resolution is resolution-high.
 *
 * @param [in] resolution One of the preset resolution value in EnumResolution.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     [cameraEnhancer setResolution:EnumRESOLUTION_HIGH];
 * @endcode
*/
- (void)setResolution:(EnumResolution)resolution;

/**
 * Get the current resolution.
 * 
 * @return A NSString that refers to the current resolution.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     NSString* resolution = [cameraEnhancer getResolution];
 * @endcode
*/
- (NSString*)getResolution;

/**
 * Specify a scan region for the camera. The video frames will be cropped based on the scan region.
 *
 * @param [in] scanRegion An iRegionDefinition value that refers to the scan region setting.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     NSError *error = [[NSError alloc] init];
     iRegionDefinition *scanRegion = [[iRegionDefinition alloc] init];
     scanRegion.regionTop = 30;
     scanRegion.regionBottom = 70;
     scanRegion.regionLeft = 15;
     scanRegion.regionRight = 85;
     scanRegion.regionMeasuredByPercentage = 1;
     [cameraEnhancer setScanRegion:scanRegion error:&scanRegionError];
 * @endcode
*/
- (BOOL)setScanRegion:(iRegionDefinition* _Nullable)scanRegion error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(setScanRegion(_:));

/**
 * Get the current setting of the scan region.
 *
 * @return An iRegionDefinition value that refers to the current scan region setting.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     [cameraEnhancer getScanRegion];
 * @endcode
*/
- (iRegionDefinition*)getScanRegion;

/**
 * Update advanced parameter settings from a JSON file.
 *
 * @param [in] filePath A JSON file that represents the content of the settings.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
     NSError *error = [[NSError alloc] init];
     [cameraEnhancer updateAdvancedSettingsFromFile:@"The file path of your advanced settings" error:&error];
 * @endcode
*/
- (BOOL)updateAdvancedSettingsFromFile:(NSString*)filePath error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(updateAdvancedSettingsFromFile(_:));

/**
 * Update advanced parameter settings from a JSON string.
 *
 * @param [in] JsonString A JSON string that represents the content of the settings.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
     NSError *error = [[NSError alloc] init];
     [cameraEnhancer updateAdvancedSettingsFromFile:@"The file path of your advanced settings" error:&error];
 * @endcode
*/
- (BOOL)updateAdvancedSettingsFromString:(NSString*)JsonString error:(NSError * _Nullable * _Nullable)error NS_SWIFT_NAME(updateAdvancedSettingsFromString(_:));

/**
 * Open the camera.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];

     [cameraEnhancer open];
 * @endcode
*/
- (void)open;

/**
 * Close the camera.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
     DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
     
     [cameraEnhancer close];
 * @endcode
*/
- (void)close;

- (CGFloat)getMaxZoomFactor;

- (BOOL)selectCameraWithPosition:(EnumCameraPosition)position error:(NSError * _Nullable * _Nullable)error;

- (EnumCameraPosition)getCameraPosition;

- (iImageData * _Nullable)getImage;

@end

NS_ASSUME_NONNULL_END
