//
//  UIButton+BXHCache.h
//  BXHNetWorkSDK
//
//  Created by 步晓虎 on 2017/4/17.
//  Copyright © 2017年 woshishui. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIButton (BXHCache)


/**
 设置图片

 @param urlStr 图片地址
 @param state btn图片状态
 */
- (void)bxh_setImageWithUrlStr:(NSString *_Nonnull)urlStr forState:(UIControlState)state;

/**
 设置图片
 

 @param urlStr 图片地址
 @param state btn图片状态
 @param placeholderImage 默认图片
 */
- (void)bxh_setImageWithUrlStr:(NSString *_Nonnull
                                )urlStr forState:(UIControlState)state placeholderImage:(UIImage *_Nullable)placeholderImage;


/**
 设置图片

 @param urlStr 图片地址
 @param state btn图片状态
 @param placeholderImage 默认图片
 @param completeBlock 完成回调可能  image可能为空
 */
- (void)bxh_setImageWithUrlStr:(NSString *_Nonnull)urlStr forState:(UIControlState)state placeholderImage:(UIImage *)placeholderImage completeBlock:(nullable void(^)(UIImage * _Nullable image))completeBlock;


/**
 设置背景图片
 
 @param urlStr 图片地址
 @param state btn图片状态
 */
- (void)bxh_setBackgroundImageWithUrlStr:(NSString *_Nonnull)urlStr forState:(UIControlState)state;


/**
 设置背景图片

 @param urlStr 图片地址
 @param state btn图片状态
 @param placeholderImage 默认图片
 */
- (void)bxh_setBackgroundImageWithUrlStr:(NSString *_Nonnull
                                          )urlStr forState:(UIControlState)state placeholderImage:(UIImage *_Nullable)placeholderImage;


/**
 设置背景图片
 
 @param urlStr 图片地址
 @param state btn图片状态
 @param placeholderImage 默认图片
 @param completeBlock 完成回调可能  image可能为空
 */

- (void)bxh_setBackgroundImageWithUrlStr:(NSString *_Nonnull)urlStr forState:(UIControlState)state placeholderImage:(UIImage *)placeholderImage completeBlock:(nullable void(^)(UIImage * _Nullable image))completeBlock;


@end
