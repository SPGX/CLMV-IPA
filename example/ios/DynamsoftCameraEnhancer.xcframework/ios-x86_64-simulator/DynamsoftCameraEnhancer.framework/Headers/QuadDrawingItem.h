//
//  QuadDrawingItem.h
//  DynamsoftCameraEnhancer
//
//  Created by Dynamsoft on 2022/4/21.
//  Copyright © 2022 Dynamsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DrawingItem.h"

NS_ASSUME_NONNULL_BEGIN

@class iQuadrilateral;

@interface QuadDrawingItem : DrawingItem

@property (strong, nonatomic, readonly) iQuadrilateral *quad;

- (instancetype)initWithQuad:(iQuadrilateral *)quad;

@end

NS_ASSUME_NONNULL_END
