//
//  BXHCacheSupport.h
//  NetWorkTest
//
//  Created by 步晓虎 on 2017/3/17.
//  Copyright © 2017年 woshishui. All rights reserved.
//

#ifndef BXHCacheSupport_h
#define BXHCacheSupport_h

static const NSUInteger kMaxErrorRetryCount = 8;

static const NSTimeInterval kMinRetryTimeInterval = 2.0;

static const int kPathLengthMax = PATH_MAX - 64;

static NSString *const kDBFileName = @"manifest.sqlite";

static NSString *const kDBShmFileName = @"manifest.sqlite-shm";

static NSString *const kDBWalFileName = @"manifest.sqlite-wal";

static NSString *const kDataDirectoryName = @"data";

static NSString *const kTrashDirectoryName = @"trash";


typedef NS_ENUM(NSUInteger, BXHKVStorageType)
{
    /// 文件系统存储
    BXHKVStorageTypeFile = 0,
    
    /// db存储
    BXHKVStorageTypeSQLite = 1,
    
    ///选择存储
    BXHKVStorageTypeMixed = 2,
};

typedef NS_ENUM(NSUInteger, BXHCacheValueType)
{
    //文本
    BXHCacheValueTextType,
    
    //图片
    BXHCacheValuePictureType,
    
    //音频文件
    BXHCahceValueVoiceType,
    
    //视频文件
    BXHCacheValueVedioType,
};


#endif /* BXHCacheSupport_h */
