//
//  BXHRequestContainer.h
//  BXHNetWorkProduct
//
//  Created by 步晓虎 on 16/9/1.
//  Copyright © 2016年 woshishui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BXHNetWorkConstants.h"

@class BXHBaseRequest;

@interface BXHRequestContainer : NSObject

@property (nonatomic, strong) NSArray <BXHBaseRequest *>*requestAry;

@property (nonatomic, copy) BXHRequestChainSuccessHandler chainSuccessHandle;

@property (nonatomic, copy) BXHRequestChainFailHandler chainFailHandle;

@property (nonatomic, copy) BXHRequestClusterSuccessHandler clusterSuccessHandle;

@property (nonatomic, copy) BXHRequestClusterFailHandler clusterFailHandle;

/**
 *  任务链根据requestAry数组的顺序从0...往后依次请求 可以从中间终端请求
 *
 *  @param success 成功回调  需返回是否继续任务链
 *  @param failure 失败回调  需返回是否继续任务链
 */
- (void)chainRequestWithSuccess:(BXHRequestChainSuccessHandler)success failure:(BXHRequestChainFailHandler)failure;

/**
 *  任务集群发出  但是受到PartManager的MaxQueueCount影响
 *
 *  @param success 成功回调
 *  @param failure 失败回调
 */
- (void)clusterRequestWithSuccess:(BXHRequestClusterSuccessHandler)success failure:(BXHRequestClusterFailHandler)failure;

@end
