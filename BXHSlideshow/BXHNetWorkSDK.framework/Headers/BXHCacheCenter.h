//
//  BXHCacheCenter.h
//  BXHNetWorkProduct
//
//  Created by 步晓虎 on 16/8/31.
//  Copyright © 2016年 woshishui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BXHDiskCache.h"
#import "BXHMemoryCache.h"

@class BXHBaseRequest;
@class BXHResponse;

@interface BXHCacheCenter : NSObject

/**
 磁盘缓存
 */
@property (nonatomic, strong, readonly) BXHDiskCache *diskCache;

/**
 内存缓存
 */
@property (nonatomic, strong, readonly) BXHMemoryCache *memoryCache;


/**
 *  单例
 *
 *  @return cache
 */
+ (BXHCacheCenter *)defultCenter;


/**
 *  把request存储到memory
 *
 *  @param request cacheRequest
 */
- (void)cacheRequestToMemory:(BXHBaseRequest *)request;

/**
 *  把request存储到Disk
 *
 *  @param request cacheRequest
 */
- (void)cacheRequestToDisk:(BXHBaseRequest *)request;

/**
 *  获取cache从memory
 *
 *  @param request cacheRequest
 *
 *  @return response
 */
- (BXHResponse *)getCacheRequestFromMemory:(BXHBaseRequest *)request;

/**
 *  获取cache从
 *
 *  @param request cacheRequest
 *
 *  @return response
 */
- (BXHResponse *)getCacheRequestFormDisk:(BXHBaseRequest *)request;

/**
 *  删除cache从Memory
 *
 *  @param request cacheRequest
 */
- (void)removeCacheFromMemory:(BXHBaseRequest *)request;

/**
 *  删除cache从disk
 *
 *  @param request cacheRequest
 */
- (void)removeCacheFromDisk:(BXHBaseRequest *)request;

/**
 *  清除所有memoryCache
 */
- (void)cleanAllMemoryCache;

/**
 *  清除所有diskCache
 */
- (void)cleanAllDiskCache;


/**
 异步删除

 @param endBlock 回调
 */
- (void)cleanAllDiskCacheWithBlock:(void (^)())endBlock;

@end
