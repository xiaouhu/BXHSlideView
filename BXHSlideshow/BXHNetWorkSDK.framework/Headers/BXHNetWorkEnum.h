//
//  BXHNetWorkEnum.h
//  BXHNetWork
//
//  Created by 步晓虎 on 16/8/30.
//  Copyright © 2016年 woshishui. All rights reserved.
//

#ifndef BXHNetWorkEnum_h
#define BXHNetWorkEnum_h

//请求方式
typedef NS_ENUM(NSInteger, BXHRequestMethod) {
    BXHRequestMethodGet,
    BXHRequestMethodPost,
    BXHRequestMethodHead,
    BXHRequestMethodPut,
    BXHRequestMethodDelete,
    BXHRequestMethodPatch
};

//返回的数据解析
typedef NS_ENUM(NSInteger, BXHResponseSerializerType) {
    //适用与普通请求
    BXHResponseSerializerTypeJSON = 0,
    //适用于文件传输 数据流
    BXHResponseSerializerTypeRawData,
};

//请求数据解析
typedef NS_ENUM(NSInteger, BXHRequestSerializerType) {
    //适用与普通请求
    BXHRequestSerializerTypeJSON = 0,
    //适用于文件传输 数据流
    BXHRequestSerializerTypeRawData,
};

typedef NS_ENUM(NSInteger, BXHRequestStatus) {
    //等待状态
    BXHRequestStatusWait,
    //正在运行
    BXHRequestStatusRunning,
    //手动暂停
    BXHRequestStatusStop,
//    //手动取消
//    BXHRequestStatus,
    //正常结束/已完成
    BXHRequestStatusCompleteOrCanceled
};

typedef NS_ENUM(NSInteger, BXHResponseFromType) {
    //网络
    BXHResponseFromeNet,
    //内存
    BXHResponseFromMemory,
    //磁盘
    BXHResponseFromDisk,
};


// 网络请求策略:
typedef NS_ENUM(NSUInteger, BXHRequestCachePolicy) {
    
    // 永远忽略缓存,仅读远程数据
    BXHRequestReloadRemoteDataIgnoringCacheData,

    // 优先先读取内存缓存,若读取成功,不再发起请求,反之读远程数据
    BXHRequestReturnMemoryCacheDataElseReloadRemoteData,
    
    // 优先先读取缓存,若读取成功,不再发起请求,反之读远程数据
    BXHRequestReturnCacheDataElseReloadRemoteData,

    // 优先先读取内存缓存,若读取成功,先执行回调逻辑,再读远程数据,反之读远程数据  未实现
    BXHRequestReturnMemoryCacheDataThenReloadRemoteData,
    
    // 优先先读取缓存,若读取成功,先执行回调逻辑,再读远程数据,反之读远程数据  未实现
    BXHRequestReturnCacheDataThenReloadRemoteData,

    // 优先读取远程数据,若读取失败,读取内存缓存
    BXHRequestReloadRemoteDataElseReturnMemoryCacheData,
    
    // 优先读取远程数据,若读取失败,读取缓存
    BXHRequestReloadRemoteDataElseReturnCacheData
};

#endif /* BXHNetWorkEnum_h */
