//
//  Dynamsoft Camera Enhancer SDK
//
//  Copyright © 2021 Dynamsoft. All rights reserved.
//
#import <DynamsoftCore/DynamsoftCore.h>

NS_ASSUME_NONNULL_BEGIN
static NSString* _Nonnull const DCEErrorDomain = @"com.dynamsoft.cameraEnhancer.error";

/**
 * Describes the error codes.
 * @enum EnumDCEErrorCode
 */
typedef NS_ENUM(NSInteger, EnumDCEErrorCode)
{
    /** OK*/
    EnumDCEErrorCode_OK                             = 0,
    
    /** Unknown error. */
    EnumDCEErrorCode_UNKNOWN                        = -10000,
    
    /** The license is invalid. */
    EnumDCEErrorCode_LICENSE_INVALID                = -10001,
    
    /** The license has expired.*/
    EnumDCEErrorCode_LICENSE_EXPIRED                = -10002,
    
    /** The camera module is not exist. */
    EnumDCEErrorCode_CAMERA_MODULE_NOT_EXIST        = -10003,
    
    /** The file is not found.*/
    EnumDCEErrorCode_FILE_NOT_FOUND                 = -10004,
    
    /** The file format error. */
    EnumDCEErrorCode_FILE_FORMAT_ERROR              = -10005,
    
    /** The input value does not exist in the camera ID list. */
    EnumDCEErrorCode_CAMERA_ID_NOT_EXIST            = -10006,
    
    /** Failed to parse the JSON data. */
    EnumDCEErrorCode_JSON_PARSE_FAILED              = -10030,
    
    /** The input parameter is invalid. */
    EnumDCEErrorCode_PARAMETER_VALUE_INVALID        = -10038,
    
    /** Failed to request the license file. */
    EnumDCEErrorCode_REQUEST_FAILED                 = -10044,
    
    /** No license.*/
    EnumDCEErrorCode_NO_LICENSE                     = -20000,
    
    /** The handshake code is invalid. */
    EnumDCEErrorCode_HANDSHAKE_CODE_INVALID         = -20001,
    
    /** Failed to read or write license cache. */
    EnumDCEErrorCode_LICENSE_BUFFER_FAILED          = -20002,

    /** Falied to synchronize license info wirh license tracking server. */
    EnumDCEErrorCode_LICENSE_SYNC_FAILED            = -20003,
    
    /** Device does not match with license buffer. */
    EnumDCEErrorCode_DEVICE_NOT_MATCH               = -20004,

    /** Falied to bind device. */
    EnumDCEErrorCode_BIND_DEVICE_FAILED             = -20005,
    
    /** Interface InitLicenseFromDLS can not be used together with other license initiation interfaces. */
    EnumDCEErrorCode_LICENSE_INTERFACE_CONFLICT     = -20006,
    
    /** License Client dll is missing.*/
    EnumDCEErrorCode_LICENSE_CLIENT_DLL_MISSING     = -20007,
    
    /**Instance count is over limited.*/
    EnumDCEErrorCode_INSTANCE_COUNT_OVER_LIMITED    = -20008,

    /** Interface InitLicenseFromDLS has to be called before creating any SDK objects. */
    EnumDCEErrorCode_LICENSE_INIT_SEQUENCE_FAILED   = -20009,
    
    /** Trial License*/
    EnumDCEErrorCode_TRIAL_LICENSE                  = -20010,

    /** Failed to reach License Tracking Server.*/
    EnumDCEErrorCode_FAILED_TO_REACH_DLS            = -20200
};

/**
* The enumeration of resolution.
*/
typedef NS_ENUM(NSInteger, EnumResolution)
{
    /** Set the video streaming to the auto selected resolution.*/
    EnumRESOLUTION_AUTO NS_SWIFT_NAME(EnumRESOLUTION_AUTO)   = 0,

    /** Set the video streaming to the 480P resolution.*/
    EnumRESOLUTION_480P NS_SWIFT_NAME(EnumRESOLUTION_480P)   = 1,

    /** Set the video streaming to the 720P resolution.*/
    EnumRESOLUTION_720P NS_SWIFT_NAME(EnumRESOLUTION_720P)   = 2,

    /** Set the video streaming to the 480P resolution.*/
    EnumRESOLUTION_1080P NS_SWIFT_NAME(EnumRESOLUTION_1080P) = 3,

    /** Set the video streaming to the 4K resolution.*/
    EnumRESOLUTION_4K NS_SWIFT_NAME(EnumRESOLUTION_4K)       = 4
} NS_SWIFT_NAME(EnumResolution);

/**
* The enumeration of camera status.
*/
typedef NS_ENUM(NSInteger, EnumCameraState) {

    /** The camera is opening.*/
    EnumCAMERA_STATE_OPENING NS_SWIFT_NAME(EnumCAMERA_STATE_OPENING)  = 0,

    /** The camera is opened.*/
    EnumCAMERA_STATE_OPENED  NS_SWIFT_NAME(EnumCAMERA_STATE_OPENED)   = 1,

    /** The camera is closing.*/
    EnumCAMERA_STATE_CLOSING  NS_SWIFT_NAME(EnumCAMERA_STATE_CLOSING)   = 2,

    /** The camera is closed.*/
    EnumCAMERA_STATE_CLOSED  NS_SWIFT_NAME(EnumCAMERA_STATE_CLOSED)   = 3
} NS_SWIFT_NAME(EnumCameraState);

/**
* The enumeration of camera enhancer features. The a valid license is required when using camera enhancer features.
*/
typedef NS_ENUM(NSInteger, EnumEnhancerFeatures) {

    /** Enable frame filter feature of the camera enhancer to make a filter out the low-quality frames*/
    EnumFRAME_FILTER NS_SWIFT_NAME(EnumFRAME_FILTER)   = 0X01,
    
    /** Enable sensor control to filter out all the frames when the device is shaking.*/
    EnumSENSOR_CONTROL NS_SWIFT_NAME(EnumSENSOR_CONTROL) = 0X02,

    /** Enhanced focus helps low-end devices on focusing.*/
    EnumENHANCED_FOCUS NS_SWIFT_NAME(EnumENHANCED_FOCUS) = 0X04,

    /** Fast mode crop the video frames to improve the processing speed.*/
    EnumFAST_MODE NS_SWIFT_NAME(EnumFAST_MODE) = 0X08,

    /** Enable the camera zoom-in automatically when barcode is far away.*/
    EnumAUTO_ZOOM NS_SWIFT_NAME(EnumAUTO_ZOOM) = 0X10,
    
    EnumSMART_TORCH NS_SWIFT_NAME(EnumSMART_TORCH) = 0X20,
	
	EnumALL NS_SWIFT_NAME(EnumALL) = 0X3F
} NS_SWIFT_NAME(EnumEnhancerFeatures);

typedef NS_ENUM(NSInteger, EnumFrameQuality) {

    /** The frame quality is measured to be high.*/
    EnumFRAME_QUALITY_HIGH NS_SWIFT_NAME(EnumFRAME_QUALITY_HIGH)   = 0,

    /** The frame quality is measured to be low. The low-quality frames will be discarded by frame filter.*/
    EnumFRAME_QUALITY_LOW NS_SWIFT_NAME(EnumFRAME_QUALITY_LOW) = 1,

    /** The frame is not measured (frame filter feature is not enabled).*/
    EnumFRAME_QUALITY_UNKNOWN NS_SWIFT_NAME(EnumFRAME_QUALITY_UNKNOWN) = 2
} NS_SWIFT_NAME(EnumFrameQuality);

typedef NS_ENUM(NSInteger, EnumCameraPosition){
    EnumCameraPositionBack     =   0,
    EnumCameraPositionFront    =   1
};

/**
* DCEFrame stores the frame information for further processing.
*/
@interface DCEFrame : iImageData

/** The frame ID.*/
@property (nonatomic, assign) NSInteger frameID;

/** The ID of the cropped frame.*/
@property (nonatomic, assign) NSInteger fastFrameID;

/** Frame quality that measured by frame filter feature.*/
@property (nonatomic, assign) EnumFrameQuality quality;

/** True: The frame is cropped; False: It is an original frame*/
@property (nonatomic, assign) BOOL isCropped;

/** The crop region of the cropped frames*/
@property (nonatomic, assign) CGRect cropRegion;

@property (nonatomic, assign) NSInteger originalWidth;

@property (nonatomic, assign) NSInteger originalHeight;

/** Buffered image data*/
@property (assign, nonatomic) CVImageBufferRef imageBuffer;

/** The method will transfer the DCEFrame to a UIImage.*/
- (nullable UIImage *)toUIImage;

/** Initialize the DCEFrame*/
- (instancetype)initWithBuffer:(NSData *)bytes width:(NSInteger)width height:(NSInteger)height stride:(NSInteger)stride format:(EnumImagePixelFormat)format frameID:(NSInteger)frameID orientation:(NSInteger)orientation quality:(EnumFrameQuality)quality isCropped:(BOOL)isCropped cropRegion:(CGRect)cropRegion originalWidth:(NSInteger)originalWidth originalHeight:(NSInteger)originalHeight imageBuffer:(nonnull CVImageBufferRef)imageBuffer;
@end

/**
 * Protocol for a delegate to handle callback when DCEFrame is returned.
 */
@protocol DCEFrameListener <NSObject>

@required

/**
 * The callback of DCEFrame.
 *
 * @param [in,out] frame A DCEFrame object.
 * @param [in,out] timeStamp The time stamp that records when the frame is output.
 *
 * @par Code Snippet:
 * @code
 *    DCECameraView *scanView = [DCECameraView cameraWithFrame:self.view.bounds];
      DynamsoftCameraEnhancer *cameraEnhancer = [[DynamsoftCameraEnhancer alloc] initWithView:scanView];
      
      [cameraEnhancer addListener:self];
      
      - (void)frameOutPutCallback:(DCEFrame *)frame timeStamp:(NSTimeInterval)timeStamp{
          //TODO add your code for license verification
      }
 * @endcode
 */
- (void)frameOutPutCallback:(DCEFrame*)frame timeStamp:(NSTimeInterval)timeStamp;

@end

/**
 * Protocol for a delegate to handle callback when license verification message returned.
 */
@protocol DCELicenseVerificationListener <NSObject>

@required
/**
 * The callback of license server.
 *
 * @param [in,out] isSuccess Whether the license verification was successful.
 * @param [in,out] error The error message from license server.
 *
 * @par Code Snippet:
 * @code
 *    [DynamsoftCameraEnhancer initLicense:@"Your license key" verificationDelegate:self];
 *    DynamsoftCameraEnhancer *dce = [[DynamsoftCameraEnhancer alloc] init];
 *    - (void)DCELicenseVerificationCallback:(bool)isSuccess error:(NSError * _Nullable)error
 *    {
 *        //TODO add your code for license verification
 *    }
 * @endcode
 */
- (void)DCELicenseVerificationCallback:(bool)isSuccess error:(NSError * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
