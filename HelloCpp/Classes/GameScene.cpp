#include "GameScene.h"
#include "AppMacros.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;


CCScene* Game::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Game *layer = Game::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Game::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
	this->isTouchEnabled();

	//PUMP UP THE VOLUME DOOD
	//SimpleAudioEngine::sharedEngine()->preloadEffect("block_break.wav");
	//SimpleAudioEngine::sharedEngine()->preloadEffect("ball_hit_paddle.wav");

	//Use these when we want to play the sounds
	//SimpleAudioEngine::sharedEngine()->playEffect("block_break.wav"); 
	//SimpleAudioEngine::sharedEngine()->playEffect("ball_hit_paddle.wav"); 


    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    // add game background
    CCSprite* pSprite = CCSprite::create("GameBG.png");
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);


	//Player Score Display
	int playerScore = 0;
	CCLabelTTF* pLabel = CCLabelTTF::create("Score:"+playerScore, "Arial", TITLE_FONT_SIZE);
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height - pLabel->getContentSize().height));
    this->addChild(pLabel, 1);


    CCSprite* block11 = CCSprite::create("blueBlock.png");
	CCSprite* block12 = CCSprite::create("redBlock.png");
	CCSprite* block13 = CCSprite::create("greenBlock.png");
	CCSprite* block14 = CCSprite::create("yellowBlock.png");
	CCSprite* block15 = CCSprite::create("orangeBlock.png");

	CCSprite* block21 = CCSprite::create("orangeBlock.png");
	CCSprite* block22 = CCSprite::create("yellowBlock.png");
	CCSprite* block23 = CCSprite::create("greenBlock.png");
	CCSprite* block24 = CCSprite::create("redBlock.png");
	CCSprite* block25 = CCSprite::create("blueBlock.png");

	CCSprite* paddle = CCSprite::create("paddle.png");

	CCSprite* ball = CCSprite::create("ball.png");

    // position everything  on the screen

	//Row 1
	block11->setPosition(ccp(floor(visibleSize.width/5 + origin.x), pLabel->getPositionY()+10));
	//block12->setPosition(ccp(block11->getPositionX+block11->getContentSize().width, pLabel->getPositionY+10));
	//block13->setPosition(ccp(block12->getPositionX+block11->getContentSize().width, pLabel->getPositionY+10));
	//block14->setPosition(ccp(block13->getPositionX+block11->getContentSize().width, pLabel->getPositionY+10));
	//block15->setPosition(ccp(block14->getPositionX+block11->getContentSize().width, pLabel->getPositionY+10));


	//Row 2
	//block21->setPosition(ccp(visibleSize.width/5 + origin.x, pLabel->getPositionY+10));
	//block22->setPosition(ccp(visibleSize.width/5 + origin.x, pLabel->getPositionY+10));
	//block23->setPosition(ccp(visibleSize.width/5 + origin.x, pLabel->getPositionY+10));
	//block24->setPosition(ccp(visibleSize.width/5 + origin.x, pLabel->getPositionY+10));
	//block25->setPosition(ccp(visibleSize.width/5 + origin.x, pLabel->getPositionY+10));

	//paddle->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + paddle->getContentSize().height/2));

	//ball->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + paddle->getContentSize().height*5));


    // add block sprites row 1 to the layer
    //this->addChild(block11, 2);
	//this->addChild(block12, 2);
	//this->addChild(block13, 2);
	//this->addChild(block14, 2);
	//this->addChild(block15, 2);

	// add block sprites row 2 to the layer
    //this->addChild(block21, 2);
	//this->addChild(block22, 2);
	//this->addChild(block23, 2);
	//this->addChild(block24, 2);
	//this->addChild(block25, 2);

	//this->addChild(paddle, 2);
	//this->addChild(ball, 2);



	//Once we finished adding everything start the scheduler
	//this->scheduleUpdate(); 	//This calls update on every frame or we can use this->schedule(schedule_selector(TestLayer::tick2), 0.5f);	//which gets called on a rough interval of however many seconds

    return true;
}

void Game::draw()
{
	// restore default GL states
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);	
}
/*
void Game::update(ccTime dt){	}
// Touch first detected
void Game::ccTouchesBegan( CCTouch *touches, CCEvent * event) {
	
	//Update paddle to where ever touch X position is

	CCTouch *myTouch = (CCTouch *)touches->anyObject();
    CCPoint location = myTouch->locationInView(myTouch->view());
    location = CCDirector::sharedDirector()->convertToGL(location);
    b2Vec2 locationWorld = b2Vec2(location.x/PTM_RATIO, location.y/PTM_RATIO);
    
    if (_paddleFixture->TestPoint(locationWorld)) {
        b2MouseJointDef md;
        md.bodyA = _groundBody;
        md.bodyB = _paddleBody;
        md.target = locationWorld;
        md.collideConnected = true;
        md.maxForce = 1000.0f * _paddleBody->GetMass();
        
        _mouseJoint = (b2MouseJoint *)_world->CreateJoint(&md);
        _paddleBody->SetAwake(true);
    }



}
// Touches moved
void Game::ccTouchesMoved( CCTouch *touches, CCEvent * event) {

	//Update paddle to new x position

	CCTouch *myTouch = (CCTouch *)touches->anyObject();
    CCPoint location = myTouch->locationInView(myTouch->view());
    location = CCDirector::sharedDirector()->convertToGL(location);

}
// User took finger off screen
void Game::ccTouchesEnded( CCTouch *touches, CCEvent * event) {
	
UITouch *touch = [ touches anyObject];

CGPoint new_location = [touch locationInView: [touch view]];
new_location = [[CCDirector sharedDirector] convertToGL:new_location];
NSLog(@"y: %1f", new_location.x);
NSLog(@"x: %1f", new_location.y);

}
// Touch was somehow interrupted
void Game::ccTouchesCancelled( CCTouch *touches, CCEvent * event) {

	//Do nothing?
}
*/
/*
void Game::startOptionsMenu(CCObject* pSender)
{
	CCScene *pOptionsScene = Game::scene();
	CCDirector::sharedDirector()->replaceScene(pOptionsScene);
}


void Game::ballMovement(CCObject* pSender)
{
	CCAction *moveAction = CCMoveBy::actionWithDuration(2.0f, CGPointMake(50.0f,0.0f)); 
	ball->runAction(moveAction);
}

*/