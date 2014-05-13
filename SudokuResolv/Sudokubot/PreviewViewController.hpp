//
//Copyright 2011 Haoest
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

//
//  PreviewViewController.h
//  Sudokubot
//
//  Created by Haoest on 5/28/11.
//  Copyright 2011 none. All rights reserved.
//

#import "rootViewDelegate.h"
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <iAd/iAd.h>

@interface PreviewViewController : UIViewController<UINavigationControllerDelegate, ADBannerViewDelegate> {
    NSMutableArray* gridViews;
    NSMutableArray* gridNumberLabels;
    int selectedGridId;
    int selectedNumpadId;
    UIView* numpadContainer;
    NSMutableArray *numpadImages;
    NSMutableArray *numpadHotRegions;
    int** hints;
}

@property(nonatomic, assign) id<RootViewDelegate> rootViewDelegate;


-(void) loadImageWithSudokuBoard:(UIImage*) img;

@end

