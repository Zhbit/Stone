//
//  Entity.h
//  Running-x
//
//  Created by Li Zhixuan on 8/30/13.
//
//

#ifndef __Running_x__Entity__
#define __Running_x__Entity__

#include "cocos2d.h"

using namespace cocos2d;

class Entity : public CCNode {
    
    
public:
    
    Entity(void);
    virtual ~Entity(void);
    
    virtual bool init();
    
    /*
     *  初始化实例,返回一个autorelease对象
     *  @return
     */
    static Entity *entity();
    
    /*
     *  暂定组件的某个动作
     *  @param tag 标识
     */
    virtual void pauseComponentActionByTag(int tag);
    
    /*
     *  暂定所有组件的动作
     */
    virtual void pauseAllComponentAction(void);
    
    /*
     *  恢复某个组件的动作
     *  @param tag 标识
     */
    virtual void resumeComponentActionByTag(int tag);
    
    /*
     *  恢复所有组件动作
     */
    virtual void resumeAllComponentAction(void);
    
    /*
     *  隐藏某个组件
     *  @param tag 标识
     */
    virtual void hideComponentActionByTag(int tag);
    
    
    /*
     *  组件下一个状态
     *  @param tag 标识
     */
    virtual void componentNextStateByTag(int tag);
    
};


#endif /* defined(__Running_x__Entity__) */
