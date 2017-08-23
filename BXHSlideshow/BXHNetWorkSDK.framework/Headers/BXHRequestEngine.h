//
//  BXHRequestEngine.h
//  BXHNetWork
//
//  Created by 步晓虎 on 16/8/30.
//  Copyright © 2016年 woshishui. All rights reserved.
//

#import <Foundation/Foundation.h>
@class BXHNetWorkPartManager;
@class BXHBaseRequest;

@interface BXHRequestEngine : NSObject

@property (nonatomic, strong) NSMutableDictionary <BXHNetWorkPartManager *,NSString *>*managers;

/**
 *  工厂方法
 *
 *  @return 返回实力
 */
+ (BXHRequestEngine *)defaultEngine;

/**
 *  发送请求
 *
 *  @param request request
 */
- (NSURLSessionTask *)sendRequest:(BXHBaseRequest *)request;

/**
 *  退出所有模块的请求
 */
- (void)cancelAllRequest;

@end
