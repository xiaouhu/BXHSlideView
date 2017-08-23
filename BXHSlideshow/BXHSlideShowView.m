//
//  BXHSlideShowView.m
//  BXHSlideshow
//
//  Created by 步晓虎 on 2017/8/23.
//  Copyright © 2017年 步晓虎. All rights reserved.
//

#import "BXHSlideShowView.h"
#import "UIView+BXHMyView.m"
#import "NSTimer+Addition.h"

typedef NS_ENUM(NSInteger, BXHSlidePanDirection)
{
    BXHSlidePanNoneDirection,
    BXHSlidePanLeftDirection,
    BXHSlidePanRightDirection,
    BXHSlidePanUpDirection,
    BXHSlidePanDownDorection
};

#define PanToSlideRatio 1
#define PageEnableDistance ([UIScreen mainScreen].bounds.size.width / 2)

@interface  BXHSlideShowView()

@property (nonatomic, strong) BXHSlideShowItem *leftItem;

@property (nonatomic, strong) BXHSlideShowItem *centerItem;

@property (nonatomic, strong) BXHSlideShowItem *rightItem;

@property (nonatomic, assign) NSInteger centerIndex;

@property (nonatomic, assign) CGPoint startPanPoint;

@property (nonatomic, assign) NSInteger rows;

@property (nonatomic, copy) NSString *itemClassName;

@property (nonatomic, strong) NSTimer *timer;

@property (nonatomic, assign) NSTimeInterval autoTime;

@end

@implementation BXHSlideShowView

- (void)dealloc
{
    if(self.timer)
    {
        [self.timer invalidate];
        self.timer = nil;
    }
}

- (instancetype)initWithDirection:(BXHSlideViewScrollDirection)direction
{
    if (self = [super init])
    {
        
        _direction = direction;
        self.itemClassName = NSStringFromClass([BXHSlideShowItem class]);
        _panGestureRecignizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panActionDeal:)];
        [self addGestureRecognizer:_panGestureRecignizer];
    }
    return self;
}

- (void)didMoveToSuperview
{
    [super didMoveToSuperview];
    [self reloadData];
}


#pragma mark - public
- (void)registItemWithClassName:(NSString *)className
{
    self.itemClassName = className;
}

- (void)reloadData
{
    self.centerIndex = 0;
    self.rows = [self.dataSource slideViewNumberOfRows:self];
    
    if (self.rows == 1)
    {
        [self.dataSource slideView:self reloadSlideItem:self.leftItem atIndex:0];
        [self.dataSource slideView:self reloadSlideItem:self.centerItem atIndex:0];
        [self.dataSource slideView:self reloadSlideItem:self.rightItem atIndex:0];
    }
    else if (self.rows == 2)
    {
        [self.dataSource slideView:self reloadSlideItem:self.leftItem atIndex:1];
        [self.dataSource slideView:self reloadSlideItem:self.centerItem atIndex:0];
        [self.dataSource slideView:self reloadSlideItem:self.rightItem atIndex:1];
    }
    else
    {
        [self.dataSource slideView:self reloadSlideItem:self.leftItem atIndex:self.rows - 1];
        [self.dataSource slideView:self reloadSlideItem:self.centerItem atIndex:0];
        [self.dataSource slideView:self reloadSlideItem:self.rightItem atIndex:1];
    }
}

- (void)autoSlideWithTime:(NSTimeInterval)time
{
    if (time <= 0)
    {
        return;
    }
    if (self.timer)
    {
        [self.timer invalidate];
        self.timer = nil;
    }
    self.timer = [NSTimer timerWithTimeInterval:time target:self selector:@selector(autoSlideTimeAction) userInfo:nil repeats:YES];
    [[NSRunLoop mainRunLoop] addTimer:self.timer forMode:NSDefaultRunLoopMode];
}


#pragma mark - private
- (void)clickAction
{
    [self.delegate slideView:self didSelectRow:self.centerIndex];
}

- (void)autoSlideTimeAction
{
    [UIView animateWithDuration:0.2 animations:^{
        self.leftItem.left = -self.width * 2;
        self.centerItem.left = -self.width;
        self.rightItem.left = 0;
    } completion:^(BOOL finished) {
        self.leftItem.left = self.width;
        [self nextShow];
    }];
}

//panAction
- (void)panActionDeal:(UIPanGestureRecognizer *)pan
{
    switch (pan.state)
    {
        case UIGestureRecognizerStateBegan:
        {
            [self.timer pauseTimer];
            self.startPanPoint = [pan locationInView:self];
        }
            break;
        case UIGestureRecognizerStateChanged:
        {
            BXHSlidePanDirection pandirection = [self commitTranslation:[pan translationInView:self]];
            CGPoint currentPoint = [pan locationInView:self];
            if (pandirection == BXHSlidePanLeftDirection)
            {
                CGFloat slideDistance = [self slideDistanceWithPanDistance:self.startPanPoint.x - currentPoint.x];
                self.leftItem.left = -self.width - slideDistance;
                self.centerItem.left = -slideDistance;
                self.rightItem.left = self.width - slideDistance;
            }
            else if (pandirection == BXHSlidePanRightDirection)
            {
                CGFloat slideDistance = [self slideDistanceWithPanDistance:currentPoint.x - self.startPanPoint.x];
                self.leftItem.left = -self.width + slideDistance;
                self.centerItem.left = slideDistance;
                self.rightItem.left = self.width + slideDistance;
            }
        }
            break;
        case UIGestureRecognizerStateCancelled:
        {
            NSLog(@"cancel");
            [self.timer resumeTimerAfterTimeInterval:1];
        }
            break;
        case UIGestureRecognizerStateEnded:
        {
            BXHSlidePanDirection pandirection = [self commitTranslation:[pan translationInView:self]];
            if (pandirection == BXHSlidePanLeftDirection)
            {
                if (self.centerItem.left < 0 && self.centerItem.left > -PageEnableDistance)
                {
                    [UIView animateWithDuration:0.2 animations:^{
                        self.leftItem.left = -self.width;
                        self.centerItem.left = 0;
                        self.rightItem.left = self.width;
                    } completion:^(BOOL finished) {
                        [self.timer resumeTimerAfterTimeInterval:1];
                    }];
                }
                else
                {
                    [UIView animateWithDuration:0.2 animations:^{
                        self.leftItem.left = -self.width * 2;
                        self.centerItem.left = -self.width;
                        self.rightItem.left = 0;
                    } completion:^(BOOL finished) {
                        [self nextShow];
                        [self.timer resumeTimerAfterTimeInterval:1];
                    }];

                }
            }
            else if (pandirection == BXHSlidePanRightDirection)
            {
                if (self.centerItem.left > 0 && self.centerItem.left > PageEnableDistance)
                {
                    [UIView animateWithDuration:0.2 animations:^{
                        self.leftItem.left = 0;
                        self.centerItem.left = self.width;
                        self.rightItem.left = self.width * 2;
                    } completion:^(BOOL finished) {
                        [self preShow];
                        [self.timer resumeTimerAfterTimeInterval:1];
                    }];

                }
                else
                {
                    [UIView animateWithDuration:0.2 animations:^{
                        self.leftItem.left = -self.width;
                        self.centerItem.left = 0;
                        self.rightItem.left = self.width;
                    } completion:^(BOOL finished) {
                        [self.timer resumeTimerAfterTimeInterval:1];
                    }];

                }

            }
        }
            break;
        default:
            break;
    }
}

- (CGFloat)slideDistanceWithPanDistance:(CGFloat)distance
{
    return distance * PanToSlideRatio;
}

- (void)nextShow
{
    if (self.centerIndex + 1 >= self.rows)
    {
        self.centerIndex = 0;
    }
    else
    {
        self.centerIndex ++;
    }
    
    BXHSlideShowItem *tempItem = self.leftItem;
    self.leftItem = self.centerItem;
    self.centerItem = self.rightItem;
    self.rightItem = tempItem;
    
    NSInteger rightIndex = (self.centerIndex + 1) >= self.rows ? 0 : (self.centerIndex + 1);
    [self.dataSource slideView:self reloadSlideItem:self.rightItem atIndex:rightIndex];
}

- (void)preShow
{
    if (self.centerIndex - 1 < 0)
    {
        self.centerIndex = self.rows - 1;
    }
    else
    {
        self.centerIndex --;
    }
    BXHSlideShowItem *tempItem = self.rightItem;
    self.rightItem = self.centerItem;
    self.centerItem = self.leftItem;
    self.leftItem = tempItem;
    
    NSInteger leftIndex = (self.centerIndex - 1) < 0 ? (self.rows - 1) : (self.centerIndex - 1);
    [self.dataSource slideView:self reloadSlideItem:self.leftItem atIndex:leftIndex];
    

}

////////////////////判断滑动方向//////////////////////////
- (BXHSlidePanDirection)commitTranslation:(CGPoint)translation
{
    
    CGFloat absX = fabs(translation.x);
    CGFloat absY = fabs(translation.y);
    
    // 设置滑动有效距离
    if (MAX(absX, absY) < 10)
        return BXHSlidePanNoneDirection;
    
    
    if (absX > absY)
    {
        if (translation.x < 0)
        {
            return BXHSlidePanLeftDirection;
        }
        else
        {
            return BXHSlidePanRightDirection;
        }
        
    }
    else if (absY > absX)
    {
        if (translation.y<0)
        {
            return BXHSlidePanUpDirection;
        }
        else
        {
            return BXHSlidePanDownDorection;
        }
    }
    else
    {
        return BXHSlidePanNoneDirection;
    }
}

//====================layOutSubViews===========================//
- (void)layoutSubviews
{
    [super layoutSubviews];
    
    NSLog(@"================LayOutSubViews==========================");
    
    self.leftItem.frame = CGRectMake(-self.width, 0, self.width, self.height);
    self.centerItem.frame = CGRectMake(0, 0, self.width, self.height);
    self.rightItem.frame = CGRectMake(self.width, 0, self.width, self.height);
}

#pragma mark - lazyLoad
- (BXHSlideShowItem *)leftItem
{
    if (!_leftItem)
    {
        _leftItem = [[NSClassFromString(self.itemClassName) alloc] init];
        _leftItem.backgroundColor = [UIColor redColor];
        [_leftItem addTarget:self action:@selector(clickAction) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:_leftItem];

    }
    return _leftItem;
}

- (BXHSlideShowItem *)centerItem
{
    if (!_centerItem)
    {
        _centerItem = [[NSClassFromString(self.itemClassName) alloc] init];
        _centerItem.backgroundColor = [UIColor yellowColor];
        [_centerItem addTarget:self action:@selector(clickAction) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:_centerItem];

    }
    return _centerItem;
}

- (BXHSlideShowItem *)rightItem
{
    if (!_rightItem)
    {
        _rightItem = [[NSClassFromString(self.itemClassName) alloc] init];
        _rightItem.backgroundColor = [UIColor greenColor];
        [_rightItem addTarget:self action:@selector(clickAction) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:_rightItem];
    }
    return _rightItem;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
