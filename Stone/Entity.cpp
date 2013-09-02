//
//  Entity.cpp
//  Running-x
//
//  Created by Li Zhixuan on 8/30/13.
//
//

#include "Entity.h"

Entity :: Entity() {

    
}

Entity *Entity :: entity() {

    Entity *entity = new Entity();
    
    if (entity && entity->init()) {
        
        entity->autorelease();
        
    }else {
    
        CC_SAFE_DELETE(entity);
    }
    
    return entity;
}

bool Entity :: init() {
    
    if (CCNode :: init()) {
        return true;
    }
    
    return false;
}

void Entity :: pauseComponentActionByTag(int tag) {

    CCNode *component = this->getChildByTag(tag);
    CCDirector::sharedDirector()->getActionManager()->pauseTarget(component);
}

void Entity :: pauseAllComponentAction() {

    for (int i=0; i<this->getChildren()->count(); i++) {
        CCNode *component = (CCNode *)this->getChildren()->objectAtIndex(i);
        CCDirector::sharedDirector()->getActionManager()->pauseTarget(component);
    }
}

void Entity :: resumeComponentActionByTag(int tag) {

    CCNode *component = this->getChildByTag(tag);
    CCDirector::sharedDirector()->getActionManager()->resumeTarget(component);
}

void Entity :: resumeAllComponentAction() {

    for (int i=0; i<this->getChildren()->count(); i++) {
        CCNode *component = (CCNode *)this->getChildren()->objectAtIndex(i);
        CCDirector::sharedDirector()->getActionManager()->resumeTarget(component);
    }
}

void Entity :: hideComponentActionByTag(int tag) {

    CCNode *component = this->getChildByTag(tag);
    component->setVisible(false);
}

void Entity :: componentNextStateByTag(int tag) {

    
}

Entity :: ~Entity() {
    
    
}











