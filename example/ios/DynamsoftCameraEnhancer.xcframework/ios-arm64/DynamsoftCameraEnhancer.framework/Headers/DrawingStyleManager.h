//
//  DrawingStyleManager.h
//  DynamsoftCameraEnhancer
//
//  Created by Dynamsoft on 2022/4/20.
//  Copyright © 2022 Dynamsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DrawingStyle.h"

#define STYLE_BLUE_STROKE  1 // for DDN 
#define STYLE_GREEN_STROKE  2 // for DBR 
#define STYLE_ORANGE_STROKE  3 // for DLR 
#define STYLE_YELLOW_STROKE  4 // for Userdefined 
#define STYLE_BLUE_STROKE_FILL  5  // for DDN Selected style 
#define STYLE_GREEN_STROKE_FILL  6  // for DBR Selected style 
#define STYLE_ORANGE_STROKE_FILL  7  // for DLR Selected style 
#define STYLE_YELLOW_STROKE_FILL  8  // for UserDefined Selected

NS_ASSUME_NONNULL_BEGIN

//@class DrawingStyle;

@interface DrawingStyleManager : NSObject

+ (DrawingStyle *)getDrawingStyle:(NSInteger)styleId;

+ (NSInteger)createDrawingStyle:(UIColor *)strokeColor strokeWidth:(CGFloat)strokeWidth fillColor:(UIColor *)fillColor textColor:(UIColor *)textColor font:(UIFont *)font;

@end

NS_ASSUME_NONNULL_END
