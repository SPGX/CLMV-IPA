//
//  Dynamsoft Camera Enhancer SDK
//
//  Copyright © 2021 Dynamsoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DCEDrawingLayer;

/**
 * DCECameraView is the class that provides UI elements control APIs.
*/
@interface DCECameraView: UIView<CALayerDelegate>

/**
 * overlayVisible is the property that controls whether highlighted overlays will be displayed on decoded barcodes.
 *       overlayVisible = true: The overlays will be displayed.
 *       overlayVisible = false: The overlays will not be displayed.
*/
@property (assign, nonatomic) BOOL overlayVisible DEPRECATED_MSG_ATTRIBUTE("DEPRECATED.");

/**
 * viewfinderVisible is the property that controls whether a viewfinder will be displayed on the UI.
 *       viewfinderVisible = true: The viewfinder will be displayed.
 *       viewfinderVisible = false: The viewfinder will not be displayed.
*/
@property (assign, nonatomic) BOOL viewfinderVisible DEPRECATED_MSG_ATTRIBUTE("DEPRECATED.");

/**
 * torchButtonVisible is the property that controls whether a torch button will be displayed on the UI. The torch button will be able to control the status of the torch.
 *       torchButtonVisible = true: The torch button will be displayed.
 *       torchButtonVisible = false: The torch button will not be displayed.
*/
@property (assign, nonatomic) BOOL torchButtonVisible;

/**
 * The static method to initialize DCECameraView.
 *
 * @param [in] frame A CGRect value that refers to the position of the view.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
 * @endcode
*/
+ (instancetype)cameraWithFrame:(CGRect)frame NS_SWIFT_NAME(init(frame:));

/**
 * The dynamic method to initialize DCECameraView.
 *
 * @param [in] frame A CGRect value that refers to the position of the view.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [[DCECameraView alloc] initWithFrame:self.view.bounds]
 * @endcode
*/
- (instancetype)initWithFrame:(CGRect)frame;

/**
 * Set the stroke color and the fill color of the overlays.
 *
 * @param [in] stroke The stroke color of the overlays.
 * @param [in] fill The fill color of the overlays.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [[DCECameraView alloc] initWithFrame:self.view.bounds]

     UIColor* strokeColor = [UIColor colorWithRed:0.1 green:0.2 blue:0.3 alpha:0.5];
     UIColor* fillColor = [UIColor colorWithRed:0.1 green:0.2 blue:0.3 alpha:0.5];
     [scanView setOverlayColour:strokeColor fill:fillColor];
 * @endcode
*/
- (void)setOverlayColor:(UIColor *)stroke fill:(UIColor*)fill DEPRECATED_MSG_ATTRIBUTE("DEPRECATED.");

/**
 * Viewfinder configurations. Set the top, bottom, left, right of the viewfinder.
 *
 * @param [in] left A float value that refers to the distance between the left border of viewfinder and the left border of DCECameraView. The distance is measured by percentage.
 * @param [in] top A float value that refers to the distance between the top border of viewfinder and the top border of DCECameraView. The distance is measured by percentage.
 * @param [in] right A float value that refers to the distance between the right border of viewfinder and the left border of DCECameraView. The distance is measured by percentage.
 * @param [in] bottom A float value that refers to the distance between the bottom border of viewfinder and the top border of DCECameraView. The distance is measured by percentage.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [[DCECameraView alloc] initWithFrame:self.view.bounds]

     [scanView setViewfinder:0.1 top: 0.3 right: 0.9 bottom: 0.7];
 * @endcode
*/
- (void)setViewfinder:(CGFloat)left top:(CGFloat)top right:(CGFloat)right bottom:(CGFloat)bottom error:(NSError * _Nullable * _Nullable)error DEPRECATED_MSG_ATTRIBUTE("DEPRECATED.");

/**
 * Display a torch button on the UI and set the position for the button.
 *
 * @param [in] torchButtonPosition A CGPoint that refers to where to display the torch button. The x/y coordinate refers to the distance between the left/top border of DCECameraView and the center of the button.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [[DCECameraView alloc] initWithFrame:self.view.bounds]

     [scanView setTorchButton:CGPointMake(100,100)];
 * @endcode
*/
- (void)setTorchButton:(CGPoint)torchButtonPosition DEPRECATED_MSG_ATTRIBUTE("DEPRECATED.");

/**
 * Set the position, size and image of the torch button.
 *
 * @param [in] frame A CGRect value that refers to the position and the size of the torch button. The position and the size are measured by dp.
 * @param [in] torchOnImage The displayed image when the torch is on.
 * @param [in] torchOffImage The displayed image when the torch is off.
 *
 * @par Code Snippet:
 * @code
     DCECameraView *scanView = [[DCECameraView alloc] initWithFrame:self.view.bounds]

     CGRect rect = {0, 0, 30, 30};
     UIImage *image1 = [[UIImage alloc]init];
     UIImage *image2 = [[UIImage alloc]init];
     [scanView setTorchButton:(rect) torchOnImage:image1 torchOffImage:image2];
 * @endcode
*/
- (void)setTorchButton:(CGRect)frame torchOnImage:(UIImage* _Nullable)torchOnImage torchOffImage:(UIImage* _Nullable)torchOffImage NS_SWIFT_NAME(setTorchButton(frame:torchOnImage:torchOffImage:));

- (DCEDrawingLayer *)getDrawingLayer:(NSInteger)layerId;

- (DCEDrawingLayer *)createDrawingLayer;

@end
NS_ASSUME_NONNULL_END
