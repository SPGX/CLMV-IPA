#import <VisionCamera/FrameProcessorPlugin.h>
#import <VisionCamera/Frame.h>

@interface QRCodeFrameProcessorPlugin : NSObject
@end

@implementation QRCodeFrameProcessorPlugin

static inline id scanQRCodes(Frame* frame, NSArray* args) {
  CMSampleBufferRef buffer = frame.buffer;
  UIImageOrientation orientation = frame.orientation;
  // code goes here
  return @[];
}

VISION_EXPORT_FRAME_PROCESSOR(scanQRCodes)

@end
