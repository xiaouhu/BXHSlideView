//
//  BXHNetWorkPartManager.h
//  BXHNetWork
//
//  Created by 步晓虎 on 16/8/30.
//  Copyright © 2016年 woshishui. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class AFHTTPSessionManager;

@class BXHBaseRequest;

@interface BXHNetWorkPartManager : NSObject 
//ip地址或域名地址
@property (nonatomic, copy) NSString *host;
//用于管理sessionTask
@property (nonatomic, strong, readonly) AFHTTPSessionManager *manager;
//全部请求
@property (nonatomic, strong, readonly) NSArray <BXHBaseRequest *> *allReuqest;
//已经运行的请求
@property (nonatomic, strong, readonly) NSArray <BXHBaseRequest *> *runningRequest;
//被停止的请求
@property (nonatomic, strong, readonly) NSArray <BXHBaseRequest *> *stopRequest;
//等待开始的请求
@property (nonatomic, strong, readonly) NSArray <BXHBaseRequest *> *waitReuqest;
//queueMaxCount
@property (nonatomic, assign) NSInteger maxQueueCount;
//valueKey 标识
@property (nonatomic, copy) NSString *valueKey;
/**
 *  创建PartManage
 *
 *  @param host          ip地址或域名
 *  @param configuration session配置
 *
 *  @return manager
 */
+ (BXHNetWorkPartManager *)mangerWithHost:(NSString *)host andsessionConfiguration:(NSURLSessionConfiguration *)configuration valueKey:(NSString *)valueKey;

/**
 *  适用于https创建证书 
 *
 *  @param certification 证书名称
 *  @param bundle 证书bundle
 *  @param allowInvalidCertificates 允许验证自签证书
 *  @param validatesDomainName 是否验证域名，当证书和server域名不一致时设置为NO
 */
- (void)httpSecurityPolicyCertification:(NSString *)certification bundle:(NSBundle *)bundle allowInvalidCertificates:(BOOL)allowInvalidCertificates validatesDomainName:(BOOL)validatesDomainName;

/**
 *  添加请求
 *
 *  @param request 加入被管理的模块
 */
- (void)addRequest:(BXHBaseRequest *)request;

/**
 *  取消摸个请求
 *
 *  @param request 被取消的请求
 */
- (void)cancelRequest:(BXHBaseRequest *)request;

/**
 *  取消所有请求
 */
- (void)cancelAllRequest;

@end
NS_ASSUME_NONNULL_END
