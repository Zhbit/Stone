#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Entity.h"

using namespace cocos2d;
using namespace CocosDenshion;

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

    Entity *e = Entity::entity();
    e->setPosition(200, 100);
    c = Component::componentWithFileName("run01.png");
    c->setComponentStateWithFileName("jump01.png");
    c->runAction(CCRepeatForever::create(c->getAnimate()));
    e->addChild(c);
    this->addChild(e);
    
    
    this->scheduleOnce(schedule_selector(HelloWorld::test), 2.0);
    
    return true;
}

void HelloWorld::test() {
    
    c->nextState();
    
    this->scheduleOnce(schedule_selector(HelloWorld::test1), 2.0);
}

void HelloWorld::test1() {
    
    c->stateByIndex(0);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
