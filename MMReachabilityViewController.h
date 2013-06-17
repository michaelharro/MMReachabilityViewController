//
//  MMReachabilityViewController.h
//  MMReachabilityViewController
//
//  Version 1.0
//
//  Created by Manuele Maggi on 28/05/2013.
//  email: manuele.maggi@gmail.com
//  Copyright (c) 2013-present Manuele Maggi. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

typedef enum {
    
    MMReachabilityModeOverlay,  //  The banner view overlay the content of the view of the viewcontroller
    MMReachabilityModeResize,   //  The banner banner appear at the topo of the view container and resize the view of the viewcontroller
    
} MMReachabilityMode;

#import <UIKit/UIKit.h>

/**
 *  if you need to update your UI when the reachablility changes make your view controller adhear to this protocol
 *  and your methods will be called when the reachablility changes.
 */
@protocol MMReachabilityDelegate <NSObject>
@optional

-(void)connectionDidBecomeReachable;
-(void)connectionDidBecomeUnReachable;

@end

@interface MMReachabilityViewController : UIViewController {
    
    @protected
    UIView *_bannerView;
	id<MMReachabilityDelegate> _reachablityDelegate;
}

/**
 *  The view to display when there is not internet connection, the width should be the same of the view of the view controller
 */
@property (nonatomic, strong) UIView *bannerView;

@property (nonatomic, strong) id<MMReachabilityDelegate> reachablityDelegate;

/**
 *  the MMReachabilityMode can't not be change after that the view has been loaded
 *  set it after the init of the view controllor or overwriting the viewDidLoad in your subclass 
 *  just before calling [super viewDidLoad]
 */
@property (nonatomic, assign) MMReachabilityMode mode;

/**
 *  The time in seconds that the banner will be visible before disappear automatically
 *  0 or negative values will make the banner permanet untill the internet connection will be available again
 */
@property (nonatomic, assign) float visibilityTime;

/**
 *  ARC forbids message send 'dealloc' so it's not possible to call [super dealloc] on subclasses, instead you can call onDealloc
 *  this will tear down all has been setted up (NSNotification observer etc...)
 */
- (void)onDealloc;

@end
