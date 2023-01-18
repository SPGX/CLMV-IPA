//
//  DrawingStyle.h
//  DynamsoftCameraEnhancer
//
//  Created by Dynamsoft on 2022/4/20.
//  Copyright © 2022 Dynamsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DrawingStyle : NSObject

@property (assign, nonatomic, readonly) NSInteger styleId;

@property (nonatomic, copy) UIColor *strokeColor;

@property (nonatomic, copy) UIColor *fillColor;

@property (nonatomic, copy) UIColor *textColor;

@property (assign, nonatomic) CGFloat strokeWidth;

@property (nonatomic, copy) UIFont *font;

- (instancetype)initWithId:(NSInteger)styleId strokeColor:(UIColor *)strokeColor strokeWidth:(CGFloat)strokeWidth fillColor:(UIColor *)fillColor textColor:(UIColor *)textColor font:(UIFont *)font;

@end

NS_ASSUME_NONNULL_END
