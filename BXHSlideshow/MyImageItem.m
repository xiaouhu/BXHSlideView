//
//  MyImageItem.m
//  BXHSlideshow
//
//  Created by 步晓虎 on 2017/8/23.
//  Copyright © 2017年 步晓虎. All rights reserved.
//

#import "MyImageItem.h"

@implementation MyImageItem

- (instancetype)init
{
    if (self = [super init])
    {
        self.imageView = [[UIImageView alloc] init];
        [self addSubview:self.imageView];
    }
    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    self.imageView.frame = self.bounds;
}
/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
