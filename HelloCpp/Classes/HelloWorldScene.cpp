#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "OptionsScene.h"
#include "GameScene.h"

using namespace cocos2d;
//using namespace CocosDenshion;


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
	this->isTouchEnabled();
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    //CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
    //                                    "CloseNormal.png",
   //                                     "CloseSelected.png",
    //                                    this,
    //                                    menu_selector(HelloWorld::menuCloseCallback));
    
	//pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                //origin.y + pCloseItem->getContentSize().height/2));

	CCMenuItem *pStartGameItem = CCMenuItemFont::create(
                                        "Start Game",
                                        this,
                                        menu_selector(HelloWorld::startGame) );
	pStartGameItem->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2));

	CCMenuItem *pGameOptions = CCMenuItemFont::create(
                                        "Options",
                                        this,
                                        menu_selector(HelloWorld::startOptionsMenu) );
	pGameOptions->setPosition(ccp(origin.x + visibleSize.width - pGameOptions->getContentSize().width/2 ,
                                origin.y + pGameOptions->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pStartGameItem, NULL);
    pMenu->setPosition(CCPointZero);
	pMenu->addChild(pGameOptions);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);


	CCLabelTTF* pLabel = CCLabelTTF::create("Ugly Brick Breaker EXTREME V0.1", "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);


	CCLabelTTF* authorLabel = CCLabelTTF::create("By: Steven Bauer", "Arial", TITLE_FONT_SIZE);
    authorLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - 30 - authorLabel->getContentSize().height));
    this->addChild(authorLabel, 2);
    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}


void HelloWorld::startGame(CCObject* pSender)
{
	CCScene *pGameScene = Game::scene();
	CCDirector::sharedDirector()->replaceScene(pGameScene);
}

void HelloWorld::startOptionsMenu(CCObject* pSender)
{
	CCScene *pOptionsScene = OptionsScene::scene();
	CCDirector::sharedDirector()->replaceScene(pOptionsScene);
	CCTransitionScene *transition = CCTransitionPageTurn::create(5.0f, pOptionsScene, false);
}