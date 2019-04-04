/*!
 @header WMPlayer.h
 
 @abstract  作者Github地址：https://github.com/zhengwenming
            作者CSDN博客地址:http://blog.csdn.net/wenmingzheng
 
 @author   Created by zhengwenming on  16/1/24
 
 @version 1.00 16/1/24 Creation(版本信息)
 
   Copyright © 2016年 郑文明. All rights reserved.
 */


#import "WMHeader.h"
#import "WMPlayerModel.h"

@class WMPlayer;
@protocol WMPlayerDelegate <NSObject>
@optional
///播放器事件
//点击播放暂停按钮代理方法
-(void)wmplayer:(WMPlayer *)wmplayer clickedPlayOrPauseButton:(UIButton *)playOrPauseBtn;
//点击关闭按钮代理方法
-(void)wmplayer:(WMPlayer *)wmplayer clickedCloseButton:(UIButton *)backBtn;
//点击全屏按钮代理方法
-(void)wmplayer:(WMPlayer *)wmplayer clickedFullScreenButton:(UIButton *)fullScreenBtn;
//点击锁定🔒按钮的方法
-(void)wmplayer:(WMPlayer *)wmplayer clickedLockButton:(UIButton *)lockBtn;
//单击WMPlayer的代理方法
-(void)wmplayer:(WMPlayer *)wmplayer singleTaped:(UITapGestureRecognizer *)singleTap;
//双击WMPlayer的代理方法
-(void)wmplayer:(WMPlayer *)wmplayer doubleTaped:(UITapGestureRecognizer *)doubleTap;
//WMPlayer的的操作栏隐藏和显示
-(void)wmplayer:(WMPlayer *)wmplayer isHiddenTopAndBottomView:(BOOL )isHidden;
///播放状态
//播放失败的代理方法
-(void)wmplayerFailedPlay:(WMPlayer *)wmplayer WMPlayerStatus:(WMPlayerState)state;
//准备播放的代理方法
-(void)wmplayerReadyToPlay:(WMPlayer *)wmplayer WMPlayerStatus:(WMPlayerState)state;
//播放完毕的代理方法
-(void)wmplayerFinishedPlay:(WMPlayer *)wmplayer;
@end


@interface WMPlayer : UIView
/**
 *  播放器对应的model
 */
@property (nonatomic,retain ) WMPlayerModel   *playerModel;
/**
 *  返回按钮的样式
 */
@property (nonatomic, assign) BackBtnStyle backBtnStyle;
/**
 *  BOOL值判断当前的状态，开发者要自己维护次BOOL值
 */
@property (nonatomic,assign) BOOL    isFullscreen;

@property (nonatomic,assign,readonly) BOOL    prefersStatusBarHidden;
/** 播放器的代理 */
@property (nonatomic, weak)id <WMPlayerDelegate> delegate;
/**
 *  是否开启音量手势
 */
@property (nonatomic,assign) BOOL  enableVolumeGesture;
/**
 *  是否开启后台播放模式
 */
@property (nonatomic,assign) BOOL  enableBackgroundMode;
/**
 *  是否开启快进手势
 */
@property (nonatomic,assign) BOOL  enableFastForwardGesture;
/**
 *  是否静音
 */
@property (nonatomic,assign) BOOL  muted;
/**
 *  设置playerLayer的填充模式
 */
@property (nonatomic, assign) WMPlayerLayerGravity    playerLayerGravity;
//是否是锁定屏幕旋转状态
@property (nonatomic,assign,readonly) BOOL isLockScreen;


///------------------------------func---------------------
/**
 *  自定义实例化方法初始化方式（-方法）
 */
-(instancetype)initPlayerModel:(WMPlayerModel *)playerModel;
/**
 *  自定义类方法+初始化方式（+方法）
 */
+(instancetype)playerWithModel:(WMPlayerModel *)playerModel;

/**
 *  播放
 */
- (void)play;

/**
 * 暂停
 */
- (void)pause;
/**
 *  获取正在播放的时间点
 *
 *  @return double的一个时间点
 */
- (double)currentTime;

/**
 *  获取正在播放的时间点
 *
 *  @return 总时间
 */
- (double)getTotalTime;

/**
 * 重置播放器,然后切换下一个播放资源
 */
- (void )resetWMPlayer;
/**
 * 版本号
 */
+(NSString *)version;
//获取当前的旋转状态
+(CGAffineTransform)getCurrentDeviceOrientation;
+(BOOL)IsiPhoneX;
@end

