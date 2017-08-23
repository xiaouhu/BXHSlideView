//
//  BXHNetWorkProtocol.h
//  BXHNetWork
//
//  Created by 步晓虎 on 16/8/30.
//  Copyright © 2016年 woshishui. All rights reserved.
//

#ifndef BXHNetWorkProtocol_h
#define BXHNetWorkProtocol_h

@class BXHBaseRequest;
@protocol AFMultipartFormData;

@protocol BXHReuqestDelegate <NSObject>

@optional
- (void)requestWillStart:(BXHBaseRequest*)request;
- (void)requestDidStart:(BXHBaseRequest *)request;
//- (void)requestCanceled:(BXHBaseRequest*)request;
- (void)requestDidStop:(BXHBaseRequest*)request;
- (void)requestDidCancelOrComplete:(BXHBaseRequest*)request;

@end

@protocol BXHMultipartFormData <AFMultipartFormData>

@end

@protocol BXHRequestCallBack <NSObject>

- (void)successCallBack;

- (void)failCallBack;

@end


#endif /* BXHNetWorkProtocol_h */
