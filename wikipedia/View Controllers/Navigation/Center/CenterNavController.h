//  Created by Monte Hurd on 12/16/13.
//  Copyright (c) 2013 Wikimedia Foundation. Provided under MIT-style license; please copy and modify!

#include "SectionEditorViewController.h"
#include "MWPageTitle.h"

typedef enum {
    DISCOVERY_METHOD_SEARCH,
    DISCOVERY_METHOD_RANDOM,
    DISCOVERY_METHOD_LINK,
    DISCOVERY_METHOD_BACKFORWARD
} ArticleDiscoveryMethod;

@interface CenterNavController : UINavigationController <UINavigationControllerDelegate>

@property (nonatomic, readonly) BOOL isEditorOnNavstack;
@property (nonatomic, readonly) SectionEditorViewController *editor;

-(void)loadArticleWithTitle: (MWPageTitle *)title
                     domain: (NSString *)domain
                   animated: (BOOL)animated
            discoveryMethod: (ArticleDiscoveryMethod)discoveryMethod
          invalidatingCache: (BOOL)invalidateCache
                 popToWebVC: (BOOL)popToWebVC;

-(void) promptFirstTimeZeroOnWithTitleIfAppropriate:(NSString *) title;
-(void) promptZeroOff;

-(ArticleDiscoveryMethod)getDiscoveryMethodForString:(NSString *)string;
-(NSString *)getStringForDiscoveryMethod:(ArticleDiscoveryMethod)method;

@property (nonatomic) BOOL isTransitioningBetweenViewControllers;

@end

//TODO: maybe use currentTopMenuTextFieldText instead of currentSearchString?
