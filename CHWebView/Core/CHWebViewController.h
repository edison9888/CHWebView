//
//  CHWebViewController.h
//
//  Created by Chausson on 16/3/9.
//  Copyright © 2016年 Chausson. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import <JavaScriptCore/JavaScriptCore.h>

@interface CHWebViewController : UIViewController

@property (nonatomic, strong)NSURL *url;// defult is WKWebView ,WKWebView have't cache ,you can choose UIWebView before ViewDidLoad.
@property (nonatomic, strong)UIColor *tintColor;

@property (nonatomic, assign ,getter= isuseUIWebView)BOOL useUIWebView;

@property (nonatomic, assign ,getter= isHiddenProgressView)BOOL hiddenProgressView; // defult is NO ,if you set Yes the progressBar will not show .
/**
 * @brief 根据远端URL地址加载
 */
- (instancetype)initWithURL:(NSString *)url;
/**
 * @brief 根据本地文件路径加载
 */
- (instancetype)initWithFile:(NSString *)url;

- (instancetype)initWithURL:(NSString *)url withOutNavtionBar:(BOOL)hidden;

- (instancetype)initWithFile:(NSString *)url withOutNavtionBar:(BOOL)hidden;


- (void)invokeJavaScript:(NSString *)function;

- (void)invokeJavaScript:(NSString *)function completionHandler:(void (^)( id, NSError * error))completionHandler;
/**
 * @brief html前端利用协议中href跳转完后的事件
 */
- (void)completionHref:(NSDictionary *)parameters;
/**
 * @brief 注册js调用oc的名称
 * @return 子类需要返回注册的名称，以及实现方法
 */
- (NSArray <NSString *>*)registerJavascriptName;

@end
