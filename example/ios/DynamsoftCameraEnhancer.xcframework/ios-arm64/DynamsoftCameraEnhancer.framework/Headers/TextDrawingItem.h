//
//  TextDrawingItem.h
//  DynamsoftCameraEnhancer
//
//  Created by Dynamsoft on 2022/4/21.
//  Copyright © 2022 Dynamsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DrawingItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface TextDrawingItem : DrawingItem

@property (nonatomic, copy, readonly) NSString *text;

@property (nonatomic, readonly) CGRect rect;

- (instancetype)initWithText:(NSString *)text rect:(CGRect)rect;

@end

NS_ASSUME_NONNULL_END
