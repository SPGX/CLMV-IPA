//
//  DCEImageEditorView.h
//  DynamsoftCameraEnhancer
//
//  Created by Dynamsoft on 2022/4/20.
//  Copyright © 2022 Dynamsoft. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class iImageData;
@class DrawingItem;
@class DCEDrawingLayer;

@interface DCEImageEditorView : UIView

- (instancetype)initWithFrame:(CGRect)frame;

- (void)setOriginalImage:(iImageData *)imageData;

- (iImageData *)getOriginalImage;

- (DrawingItem *)getSelectedDrawingItem;

- (DCEDrawingLayer *)getDrawingLayer:(NSInteger)layerId;

- (DCEDrawingLayer *)createDrawingLayer;

@end

NS_ASSUME_NONNULL_END
