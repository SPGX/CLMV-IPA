//
//  RectDrawingItem.h
//  DynamsoftCameraEnhancer
//
//  Created by Dynamsoft on 2022/4/21.
//  Copyright © 2022 Dynamsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DrawingItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface RectDrawingItem : DrawingItem

@property (nonatomic, readonly) CGRect rect;

- (instancetype)initWithRect:(CGRect)rect;

@end

NS_ASSUME_NONNULL_END
