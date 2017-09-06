//
//  ViewController.m
//  BXHSlideshow
//
//  Created by 步晓虎 on 2017/8/23.
//  Copyright © 2017年 步晓虎. All rights reserved.
//

#import "ViewController.h"
#import "BXHSlideShowView.h"
#import "MyImageItem.h"
#import <AFNetWorkSDK/AFNetworking.h>
#import <BXHNetWorkSDK/BXHNetWorkSDK.h>

@interface ViewController () <BXHSlideShowViewDelegate, BXHSlideShowViewDataSource>

@property (nonatomic, strong) BXHSlideShowView *showView;

@property (nonatomic, strong) NSArray *sourceAry;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    
    self.sourceAry = @[@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578936&di=eff1bf98d261110ca241740389d12a59&imgtype=0&src=http%3A%2F%2Fimg2.niutuku.com%2Fdesk%2F1207%2F1100%2Fbizhi-1100-7201.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578935&di=60ecee0a9e9249f2966b17d4ffb09fba&imgtype=0&src=http%3A%2F%2Fimg4.duitang.com%2Fuploads%2Fblog%2F201401%2F06%2F20140106161046_vvZWz.thumb.700_0.jpeg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383606441&di=295930eadf6ea8443374d2ea23955e52&imgtype=jpg&src=http%3A%2F%2Fg.hiphotos.baidu.com%2Fimage%2Fpic%2Fitem%2Fe7cd7b899e510fb3b993648ad333c895d1430c20.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578935&di=7eed53959a649926be03078aeeeef56f&imgtype=0&src=http%3A%2F%2Fy2.ifengimg.com%2Fa282fca64216bddb%2F2013%2F0927%2Fre_5244d39b0d5db.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578935&di=8e83f7ae3ed679da11979f50d46e0e16&imgtype=0&src=http%3A%2F%2Fd.5857.com%2Fnjhb_140411%2F003.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578935&di=509d73913be6514bafbda6031258c7f3&imgtype=0&src=http%3A%2F%2Fimg.pconline.com.cn%2Fimages%2Fupload%2Fupc%2Ftx%2Fwallpaper%2F1404%2F04%2Fc0%2F32784352_1396579157113_800x800.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383642891&di=b74aee637270ab385adc688c61322762&imgtype=jpg&src=http%3A%2F%2Fh.hiphotos.baidu.com%2Fimage%2Fpic%2Fitem%2Fa08b87d6277f9e2fd0d41e151530e924b999f3ce.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578935&di=27e45e948c13aca42b6c6a34ddaa90f5&imgtype=0&src=http%3A%2F%2Fimg1.3lian.com%2F2015%2Fa1%2F129%2Fd%2F237.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578935&di=ddbbf820714067e8e12f9fa87b92e2c4&imgtype=0&src=http%3A%2F%2Fa1.att.hudong.com%2F06%2F84%2F300001048486129257841596610.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578935&di=1ef0a0e2403b5122567188107445992a&imgtype=0&src=http%3A%2F%2Fimg.sc115.com%2Fuploads%2Fallimg%2F100719%2F2010071915420419.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578934&di=f30227124fd7874889235b9b5ea5d80e&imgtype=0&src=http%3A%2F%2Fbos.pgzs.com%2Frbpiczy%2FWallpaper%2F2011%2F3%2F11%2Faae171505eb24d7bad493c95b723c748-7.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578934&di=f27e89039801d25e8d914a52ca750296&imgtype=0&src=http%3A%2F%2Fbcs.91.com%2Frbpiczy%2FWallpaper%2F2015%2F3%2F23%2Fc5b92106d2da4d96b14fdc3c2571a675-3.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578934&di=d128b6419a15c5d82cebf5e9e2319879&imgtype=0&src=http%3A%2F%2Fscimg.jb51.net%2Fallimg%2F151214%2F14-15121414410S15.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578934&di=ce38f350a8ae2c50f5563ac3be2fb0f2&imgtype=0&src=http%3A%2F%2Fimg1.3lian.com%2F2015%2Fa1%2F129%2Fd%2F236.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578933&di=d22ed87e01d44a6db6a5a35d958fb80b&imgtype=0&src=http%3A%2F%2Fimg1.3lian.com%2F2015%2Fa1%2F129%2Fd%2F238.jpg",@"https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1503383578933&di=5c650ffbf68844ee555de83a1bea5c59&imgtype=0&src=http%3A%2F%2F5.133998.com%2F2014%2Fpic%2F000%2F356%2F03be5378af3fbdc9b83bc6ecf58ab1a1.jpg"];
    
    self.showView = [[BXHSlideShowView alloc] initWithDirection:BXHSlideViewScrollHorizontalDirection];
    [self.showView registItemWithClassName:NSStringFromClass([MyImageItem class])];
    self.showView.frame = self.view.bounds;
    self.showView.dataSource = self;
    self.showView.delegate = self;
    [self.view addSubview:self.showView];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [self.showView autoSlideWithTime:3];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (NSInteger)slideViewNumberOfRows:(BXHSlideShowView *)slideView
{
    return self.sourceAry.count;
}

- (void)slideView:(BXHSlideShowView *)slideView reloadSlideItem:(BXHSlideShowItem *)item atIndex:(NSInteger)index
{
    NSLog(@"loadIndex😇😇😇😇😇😇😇😇😇😇😇😇😇😇😇%ld",index);
    [[(MyImageItem *)item imageView] bxh_imageWithUrlStr:self.sourceAry[index] placeholderImage:nil];
}

- (void)slideView:(BXHSlideShowView *)slideView didSelectRow:(NSInteger)row
{
    NSLog(@"clickIndex 😇😇😇😇😇😇😇😇😇😇😇😍😍😍😍 %ld",row);
}

@end
