//
//  BXHDiskCache.h
//  NetWorkTest
//
//  Created by 步晓虎 on 2017/3/19.
//  Copyright © 2017年 woshishui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BXHCacheSupport.h"
NS_ASSUME_NONNULL_BEGIN

@interface BXHDiskCache : NSObject

@property (nonatomic, copy, readonly) NSString *path;

@property (readonly) NSUInteger maxSaveSqliteSize;

#pragma mark - Initializer

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 初始化方法

 @param path 路径地址
 @param maxSize sqlit中存储的最大大小
 @return 对象
 */
- (instancetype)initWithPath:(NSString *)path maxSaveSqliteSize:(NSUInteger)maxSize;

#pragma mark - Access Methods

/**
 判断是否有这个key的数据

 @param key 标识
 @return yes 有 no没有
 */
- (BOOL)containsObjectForKey:(NSString *)key;

/**
 通过key获取数据

 @param key 标识
 @return 对象
 */
- (nullable id<NSCoding>)objectForKey:(NSString *)key;


/**
 保存数据

 @param object 对象
 @param key 标识
 @param delTime 删除时间
 */
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key withDelTime:(NSTimeInterval)delTime valueType:(BXHCacheValueType)type;


/**
 获取某一类型的存储大小

 @param valueType 类型
 @return 大小
 */
- (NSInteger)getCacheSizeWithValueType:(BXHCacheValueType)valueType;


/**
 获取所有类型的数据大小

 @param valueBlock 数据返回block
 */
- (void)getCacheSizeWithValueTypeBlock:(nullable void(^)(BXHCacheValueType valueType, NSUInteger size, BOOL end))valueBlock;


/**
 获取数据库存储大小

 @return 大小
 */
- (NSUInteger)getTotalCacheSize;

/**
  通过key删除对应数据

 @param key 标识
 */
- (void)removeObjectForKey:(NSString *)key;


/**
 异步线程删除数据

 @param key 标识
 @param endBlock 结束
 */
- (void)removeObjectForKey:(NSString *)key endBlock:(void(^)())endBlock;


/**
    通过valueType删除数据

 @param type <#type description#>
 */
- (void)removeObjectsWithValueType:(BXHCacheValueType)type;

/**
 异步线程删除数据
 
 @param type 标识
 @param endBlock 结束
 */

- (void)removeObjectsWithValueType:(BXHCacheValueType)type endBlock:(void(^)())endBlock;

/**
 通过限制时间删除操过限制时间的数据

 */
- (void)removeObjectEarlierThanTime:(NSTimeInterval)limitTime;


/**
 异步删除数据

 @param limitTime 限制时间
 @param endBlock 回调
 */
- (void)removeObjectEarlierThanTime:(NSTimeInterval)limitTime endBlock:(void(^)())endBlock;

/**
 删除所有数据
 */
- (void)removeAllObjects;

- (void)removeAllObjectsEndBlock:(void (^)())endBlock;

@end
NS_ASSUME_NONNULL_END
