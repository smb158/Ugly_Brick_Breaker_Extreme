#ifndef __OPTIONSSCENE_SCENE_H__
#define __OPTIONSSCENE_SCENE_H__

#include "cocos2d.h"

class OptionsScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
	int OptionsScene::toggleSound(CCObject* pSender);
	void OptionsScene::backToMainMenu(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(OptionsScene);
};

#endif // __OPTIONS_SCENE_H__
