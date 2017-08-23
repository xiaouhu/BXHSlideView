//
//  BXHBaseRequest.h
//  BXHNetWork
//
//  Created by 步晓虎 on 16/8/30.
//  Copyright © 2016年 woshishui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BXHNetWorkEnum.h"
#import "BXHNetWorkProtocol.h"
#import "BXHNetWorkConstants.h"
#import "BXHResponse.h"
#import "BXHNetWorkPartManager.h"
#import "BXHCacheSupport.h"

/**
 *  定义成属性的时候丁成Weak引用
 */

@interface BXHBaseRequest : NSObject <BXHRequestCallBack>

//Request session task
@property (nonatomic, strong) NSURLSessionTask *task;

//请求状态
@property (nonatomic, assign) BXHRequestStatus status;

//请求url
@property (nonatomic, copy) NSString *relativeUrlString;

//请求body
@property (nonatomic, strong) id reuqestBody;

//请求方式
@property (nonatomic, assign) BXHRequestMethod method;

//请求数据解析方式
@property (nonatomic, assign) BXHRequestSerializerType requestSerializerType;

//返回数据解析方式
@property (nonatomic, assign) BXHResponseSerializerType responseSerializerType;

//超时时间 default = 60s 缓存时间
@property (nonatomic, assign) NSTimeInterval timeOut;

//请求返回数据
@property (nonatomic, strong) BXHResponse *response;

//数据缓存策略 default = BXHRequestReloadRemoteDataIgnoringCacheData
@property (nonatomic, assign) BXHRequestCachePolicy cachePolicy;

//disk和memory存储时间 default = 60  必须为60的整数倍
@property (nonatomic, assign) NSTimeInterval cacheTime;

//存储类型
@property (nonatomic, assign) BXHCacheValueType cacheType;

//用于管理多模块请求和任务管理
@property (nonatomic, weak) BXHNetWorkPartManager *manager;

//成功回调
@property (nonatomic, copy) BXHSuccessHandler successHandler;

//失败回调
@property (nonatomic, copy) BXHFailureHandler failureHandler;


//==========Method===========//

/**
 *  开始计入PartManager
 */
- (void)start;

/**
 *  暂停请求 用于上传下载   ======暂未实现
 */
- (void)stop;

/**
 *  退出请求
 */
- (void)cancel;

/**
 *  恢复请求 用于上传下载   =======暂未实现
 */
- (void)resume;

/**
 *  快速请求内部包含方法start
 *
 *  @param success 成功回调
 *  @param failure 失败回调
 */
- (void)requestWithSuccess:(BXHSuccessHandler)success failure:(BXHFailureHandler)failure;

//===================Overwrite====================//

/******子类继承---拼装请求参数*****/
- (void)serializeHTTPRequest;

/******子类继承---解析请求参数----本方法在子线程中*****/
- (void)deserializeHTTPResponse;

/**
 *  Overwrite 验证信息
 *
 *  @return Authorization fields 如果服务器需要后台 username and password
 *   first userName  last password
 */
- (NSArray*)requestAuthorizationHeaderFieldArray;

/**
 *  Overwrite 加一些特殊数据在header
 *
 *  @return HTTP Header fields
 */
- (NSDictionary*)requestHeaderFieldValueDictionary;

/**
 *  Overwrite 上传文件
 *
 *  @return BXHConstructingBlock
 */
- (BXHConstructingBlock)constructingBodyBlock;

/**
 *  Overwrite 上传进度条
 *
 *  @return BXHUploadProgressBlock
 */
- (BXHUploadProgressBlock)resumableUploadProgressBlock;

/**
 *  Overwrite 下载进度
 *
 *  @return CCDownloadProgressBlock
 */
- (BXHDownloadProgressBlock)resumableDownloadProgressBlock;


//===============================================================//
//  Delegate
//===============================================================//

- (void)addProtcolDelegate:(id <BXHReuqestDelegate>)delegate;


- (void)removeProtcolDelegate:(id <BXHReuqestDelegate>)delegate;

@end
