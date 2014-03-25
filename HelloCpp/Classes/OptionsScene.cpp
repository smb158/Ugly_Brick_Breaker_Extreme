#include "AppMacros.h"
#include "OptionsScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;


CCScene* OptionsScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    OptionsScene *layer = OptionsScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool OptionsScene::init()
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


	//Sound Variable
	int soundEnabled = 1;

	CCMenuItem *pSoundToggle = CCMenuItemFont::create(
                                        "Toggle Game Sounds",
                                        this,
                                        menu_selector(OptionsScene::toggleSound) );
	pSoundToggle->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2));

	CCMenuItem *pBackHome = CCMenuItemFont::create(
                                        "Back To Main Menu",
                                        this,
                                        menu_selector(OptionsScene::backToMainMenu) );
	pBackHome->setPosition(ccp(origin.x + visibleSize.width - pBackHome->getContentSize().width/2 ,
                                origin.y + pBackHome->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pSoundToggle, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);


    /////////////////////////////
    // 3. add your codes below...

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);


	CCLabelTTF* pLabel = CCLabelTTF::create("Options Menu", "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    
    return true;
}

int OptionsScene::toggleSound(CCObject* pSender)
{
	//CCScene *pOptionsScene = HelloWorld::scene();
	//CCDirector::sharedDirector()->replaceScene(pOptionsScene);
	int soundEnabled = 1;
	return soundEnabled;
}

void OptionsScene::backToMainMenu(CCObject* pSender)
{
	CCScene *pOptionsScene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(pOptionsScene);
}
