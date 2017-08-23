//
//  BXHNetWorkConstants.h
//  BXHNetWork
//
//  Created by 步晓虎 on 16/8/30.
//  Copyright © 2016年 woshishui. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BXHBaseRequest;
@class BXHResponse;
@protocol BXHMultipartFormData;


typedef void (^BXHSuccessHandler)(BXHBaseRequest *request);

typedef void (^BXHFailureHandler)(NSError *error, BXHBaseRequest *request);

typedef void (^BXHConstructingBlock)(id<BXHMultipartFormData> formData);

typedef void (^BXHDownloadProgressBlock)(NSProgress *downloadProgress);

typedef void (^BXHUploadProgressBlock)(NSProgress *uploadProgress);

typedef BOOL (^BXHRequestChainSuccessHandler)(BXHBaseRequest *request, BOOL end);

typedef BOOL (^BXHRequestChainFailHandler)(NSError *error, BXHBaseRequest *request, BOOL end);

typedef void (^BXHRequestClusterSuccessHandler)(BXHBaseRequest *request, BOOL end);

typedef void (^BXHRequestClusterFailHandler)(NSError *error, BXHBaseRequest *request, BOOL end);

FOUNDATION_EXTERN void BXHLog(NSString* format, ...) NS_FORMAT_FUNCTION(1, 2);


//void blockCleanUp(__strong void(^*block)(void));
//
//#ifndef onExit
//#define onExit\
//__strong void(^block)(void) __attribute__((cleanup(blockCleanUp), unused)) = ^
//#endif

#ifndef _StrFormate
#define _StrFormate(str,...) [NSString stringWithFormat:str,##__VA_ARGS__]
#endif


