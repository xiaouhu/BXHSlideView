//
//  BXHSlideShowView.h
//  BXHSlideshow
//
//  Created by 步晓虎 on 2017/8/23.
//  Copyright © 2017年 步晓虎. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BXHSlideShowItem.h"

typedef NS_ENUM(NSInteger,BXHSlideViewScrollDirection)
{
    BXHSlideViewScrollHorizontalDirection,
    BXHSlideViewScrollVerticalDirection
};

@class BXHSlideShowView;

@protocol BXHSlideShowViewDataSource <NSObject>

- (NSInteger)slideViewNumberOfRows:(BXHSlideShowView *)slideView;

- (void)slideView:(BXHSlideShowView *)slideView reloadSlideItem:(BXHSlideShowItem *)item atIndex:(NSInteger)index;

@end

@protocol BXHSlideShowViewDelegate <NSObject>

- (void)slideView:(BXHSlideShowView *)slideView didSelectRow:(NSInteger)row;

@end

@interface BXHSlideShowView : UIView <UIGestureRecognizerDelegate>

@property (nonatomic, readonly, assign) BXHSlideViewScrollDirection direction;

@property (nonatomic, weak) id <BXHSlideShowViewDataSource>dataSource;

@property (nonatomic, weak) id <BXHSlideShowViewDelegate>delegate;

@property (nonatomic, readonly, strong) UIPanGestureRecognizer *panGestureRecignizer;

- (instancetype)initWithDirection:(BXHSlideViewScrollDirection)direction;

- (void)registItemWithClassName:(NSString *)className;

- (void)reloadData;

- (void)autoSlideWithTime:(NSTimeInterval)time;

@end
