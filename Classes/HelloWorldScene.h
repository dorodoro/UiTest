#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
class HelloWorld : public cocos2d::Layer
{
  private:
    cocos2d::EventListenerTouchOneByOne *eventListener;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
  
    static cocos2d::Sprite sprite;
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

  void buttonClick(cocos2d::Ref *sender, cocos2d::ui::TouchEventType type);
  void buttonLeftClick(cocos2d::Ref *sender, cocos2d::ui::TouchEventType type);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
