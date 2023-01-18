//
//  DCEDrawingLayer.h
//  DynamsoftCameraEnhancer
//
//  Created by Dynamsoft on 2022/4/20.
//  Copyright © 2022 Dynamsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DrawingItem.h"

#define DDN_LAYER_ID    1
#define DBR_LAYER_ID    2
#define DLR_LAYER_ID    3
#define USER_REFINED_LAYER_BASE_ID  100

NS_ASSUME_NONNULL_BEGIN

@interface DCEDrawingLayer : NSObject

@property (assign, nonatomic, readonly) NSInteger layerId;

@property (assign, nonatomic) BOOL visible;

@property (nonatomic, strong, readwrite, nullable) NSArray<DrawingItem *> *drawingItems;

@property (weak, nullable) id viewId;

- (instancetype)initWithId:(NSInteger)layerId;

- (void)addDrawingItems:(NSArray<DrawingItem *> *)items;

- (void)setDrawingStyleId:(NSInteger)styleId;

- (void)setDrawingStyleId:(NSInteger)styleId state:(EnumDrawingItemState)state;

- (void)setDrawingStyleId:(NSInteger)styleId state:(EnumDrawingItemState)state mediaType:(EnumDrawingItemMediaType)mediaType;

@end

NS_ASSUME_NONNULL_END
