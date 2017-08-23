//
//  UIImageView+BXHCache.h
//  BXHNetWorkSDK
//
//  Created by 步晓虎 on 2017/4/17.
//  Copyright © 2017年 woshishui. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImageView (BXHCache)

/**
 设置图片
 
 @param urlStr 图片地址
 */
- (void)bxh_imageWithUrlStr:(NSString *)urlStr;

/**
 设置图片
 
 @param urlStr 图片地址
 @param placeholderImage 默认图片
 */
- (void)bxh_imageWithUrlStr:(NSString *)urlStr placeholderImage:(UIImage *)placeholderImage;


/**
 设置图片

 @param urlStr 图片地址
 @param placeholderImage 默认图片
 @param completeBlock 完成回调 image可能为空
 */
- (void)bxh_imageWithUrlStr:(NSString *)urlStr placeholderImage:(UIImage *)placeholderImage completeBlock:(nullable void(^)(UIImage *image))completeBlock;

/**
 设置高亮图片
 
 @param urlStr 图片地址
 */
- (void)bxh_highlightedImageWithUrl:(NSString *)urlStr;

/**
 设置高亮图片
 
 @param urlStr 图片地址
 @param placeholderImage 默认图片
 */
- (void)bxh_highlightedImageWithUrl:(NSString *)urlStr placeholderImage:(UIImage *)placeholderImage;

/**
 设置高亮图片
 
 @param urlStr 图片地址
 @param placeholderImage 默认图片
 @param completeBlock 完成回调 image可能为空
 */
- (void)bxh_highlightedImageWithUrl:(NSString *)urlStr placeholderImage:(UIImage *)placeholderImage completeBlock:(nullable void(^)(UIImage *image))completeBlock;

@end
