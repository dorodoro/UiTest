#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocos2d::ui;
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

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
    if ( !Layer::init() )
    {
        return false;
    }
  auto node = CSLoader::getInstance()->createNodeFromProtocolBuffers("MainScene.csb");
  this->addChild(node);
  
  //攻撃ボタンイベントの登録
  auto btnR = dynamic_cast<Button*>(node->getChildByTag(0));
  auto btnL = dynamic_cast<Button*>(node->getChildByTag(1));
  auto btnA = dynamic_cast<Button*>(node->getChildByTag(2));
  auto btnB = dynamic_cast<Button*>(node->getChildByTag(3));
  auto btnC = dynamic_cast<Button*>(node->getChildByTag(4));
  btnR->addTouchEventListener(this, toucheventselector(HelloWorld::buttonClick));
  btnL->addTouchEventListener(this, toucheventselector(HelloWorld::buttonClick));
  btnA->addTouchEventListener(this, toucheventselector(HelloWorld::buttonClick));
  btnB->addTouchEventListener(this, toucheventselector(HelloWorld::buttonClick));
  btnC->addTouchEventListener(this, toucheventselector(HelloWorld::buttonClick));
}

void HelloWorld::buttonClick(Ref *sender, TouchEventType type)
{
  auto btn = sender;
  log("click tag:%s", btn);
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
