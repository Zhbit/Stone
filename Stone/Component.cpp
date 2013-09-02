//
//  Component.cpp
//  Running-x
//
//  Created by Li Zhixuan on 8/30/13.
//
//

#include "Component.h"

//
//ComponentAnimate
//

//void ComponentAnimate::updateAnimateWithNewAnimation(cocos2d::CCAnimation *newAnimation) {
//    
//    this->initWithAnimation(newAnimation);
//}


//
//Component
//

Component :: Component() {

    
}

Component *Component::componentWithFileName(const char *fileName) {

    Component *component = new Component();
    
    if (component && component->initWithFile(fileName)) {
        
        component->autorelease();
        
    }else {
    
        CC_SAFE_DELETE(component);
    }
    
    return component;
}

bool Component::initWithFile(const char *fileName) {

    if (CCSprite :: initWithFile(fileName)) {
     
        m_nCurrentStateIndex = 0;
        m_fFrameAnimationInterval = 0.2f;
        
        m_pFileNameArray = new CCArray();
        m_pFileNameArray->init();
        m_pFileNameArray->retain();
        
        
        return true;
    }
    
    return false;
}

void Component::setComponentStateWithFileName(const char *fileName) {

    m_pFileNameArray->addObject(CCString::create(fileName));
    
    CCAnimation *animation = this->createAnimation(CCString::create(fileName));
    if (animation != NULL) {
        
        if (m_pAnimate == NULL) {
            m_pAnimate = new CCAnimate();
            m_pAnimate->retain();
        }
        m_pAnimate->initWithAnimation(animation);
    }
}

void Component::nextState() {

    if (m_nCurrentStateIndex > m_pFileNameArray->count()) return;
    
    this->stateByIndex(++m_nCurrentStateIndex);
}

void Component::stateByIndex(int index) {

    if (index > m_pFileNameArray->count()) return;
    
    m_nCurrentStateIndex = index;
    
    CCString *fileName = (CCString *)m_pFileNameArray->objectAtIndex(m_nCurrentStateIndex);
    
    CCAnimation *animation = this->createAnimation(fileName);
    
    if (animation) {
        
        m_pAnimate->initWithAnimation(animation);
    }
}


CCAnimation *Component::createAnimation(cocos2d::CCString *fileName) {

    char name[20];
    int number = -1;
    char suffix[20];
    
    sscanf(fileName->getCString(), "%20[^0-9]%i.%20s", name, &number, suffix);
    
    CCArray *spriteFrameArray = CCArray::create();
    
    if (number != -1) {
        
        int fileIndex = number;
        do {
            
            fileName = CCString::createWithFormat("%s%02d.%s", name, fileIndex, suffix);
            CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(fileName->getCString());
            
            if (!texture) break;
            
            CCRect rect = CCRectZero;
            rect.size = texture->getContentSize();
            CCSpriteFrame *spriteFrame = CCSpriteFrame::createWithTexture(texture, rect);
            spriteFrameArray->addObject(spriteFrame);
            
            fileIndex++;
            
        } while (1);
    }
    
    
    this->setDisplayFrame((CCSpriteFrame *)spriteFrameArray->objectAtIndex(0));
    CCAnimation *animation = CCAnimation::createWithSpriteFrames(spriteFrameArray, m_fFrameAnimationInterval);
    animation->setRestoreOriginalFrame(true);
    return animation;
}

Component::~Component() {
    
    m_pFileNameArray->release();
    m_pAnimate->release();
}

























