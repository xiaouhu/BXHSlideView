//
//  BXHResponse.h
//  BXHNetWork
//
//  Created by 步晓虎 on 16/8/30.
//  Copyright © 2016年 woshishui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BXHNetWorkEnum.h"

@class BXHBaseRequest;

@interface BXHResponse : NSHTTPURLResponse

/**
 *  初始化response
 *
 *  @param request         基础请求
 *  @param responseObject 返回的原始状态的数据
 *
 *  @return BXHResoinse
 */
- (instancetype)initWithRequest:(BXHBaseRequest *)request
                  responseData:(NSData *)resonseData;
/**
 *  初始化response
 *
 *  @param request         基础请求
 *  @param error          错误理由
 *
 *  @return BXHResoinse
 */
- (instancetype)initWithRequest:(BXHBaseRequest *)request
                  error:(NSError *)error;

@property (nonatomic, strong, readonly) NSString *responseString;

@property (nonatomic, strong, readonly) id responseObject;

@property (nonatomic, assign, readonly) NSInteger statueCode;

@property (nonatomic, strong) NSError *error;

@property (nonatomic, assign) BXHResponseFromType fromType;

@end
