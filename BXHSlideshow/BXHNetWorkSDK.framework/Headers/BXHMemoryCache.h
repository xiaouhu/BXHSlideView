//
//  BXHMemoryCache.h
//  NetWorkTest
//
//  Created by 步晓虎 on 2017/3/18.
//  Copyright © 2017年 woshishui. All rights reserved.
//

#import <Foundation/Foundation.h>

//LRU算法实现

NS_ASSUME_NONNULL_BEGIN
@interface BXHMemoryCacheItem : NSObject

@property (nonatomic, copy) NSString *key;

@property (nonatomic, strong) id object;

@property (nonatomic) NSUInteger delTime; //缓存时间

@property (nonatomic) NSUInteger accessTime; //存储时间

@end

@interface BXHMemoryCache : NSObject

@property (nonatomic, assign) NSUInteger maxCount; //最大缓存数量

@property (nonatomic, readonly) NSUInteger cacheCount; //缓存数量

/**
 初始化方法

 @param maxConut 最大缓存数量
 @return 对象
 */
 
- (instancetype)initWithLRUMaxCount:(NSUInteger)maxConut;

#pragma mark - Access Methods

/**
 保存item

 @param item 对象
 */
- (void)saveItem:(BXHMemoryCacheItem *)item;

/**
 获取item

 @param key key
 @return 返回缓存
 */
- (BXHMemoryCacheItem *)getItemWithKey:(NSString *)key;

/**
  查询有没有对应key的缓存

 @param key key
 @return 'YES' 有 'NO' 没有
 */
- (BOOL)containsObjectForKey:(NSString *)key;


/**
 删除对应key的缓存

 @param key key
 */
- (void)removeItemForKey:(NSString *)key;

/**
  删除超过时间的缓存

 @param time 时间
 */
- (void)removeItemsEarlierThanTime:(NSTimeInterval)time;


/**
 清除所有缓存
 */
- (void)removeAll;


@end
NS_ASSUME_NONNULL_END
