//
//  DrawingItem.h
//  DynamsoftCameraEnhancer
//
//  Created by Dynamsoft on 2022/4/21.
//  Copyright © 2022 Dynamsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, EnumDrawingItemState) {
    EnumDrawingItemStateDefault = 0,
    EnumDrawingItemStateSelected = 1
} NS_SWIFT_NAME(EnumDrawingItemState);

typedef NS_ENUM(NSInteger, EnumDrawingItemMediaType) {
    EnumDrawingItemMediaTypeRectangle = 0,
    EnumDrawingItemMediaTypeQuadrilateral = 1,
    EnumDrawingItemMediaTypeText = 2
} NS_SWIFT_NAME(EnumDrawingItemMediaType);

@interface DrawingItem : NSObject

@property (assign, nonatomic) NSInteger drawingStyleId;

@property (assign, nonatomic) EnumDrawingItemState state;

@property (weak, nullable) id viewId;

- (EnumDrawingItemMediaType)getMediaType;

@end

NS_ASSUME_NONNULL_END
