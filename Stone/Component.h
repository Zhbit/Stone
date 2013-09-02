//
//  Component.h
//  Running-x
//
//  Created by Li Zhixuan on 8/30/13.
//
//

#ifndef __Running_x__Component__
#define __Running_x__Component__

#include "cocos2d.h"

using namespace cocos2d;

//class ComponentAnimate : CCAnimate {
//    
//    
//public:
//    
//    /*
//     *  用于帧动画播放过程中更新LOLComponent状态时调用
//     *  @param spriteFrame 需要更新的精灵帧
//     *  @param newAnimation 需要更新的动画
//     */
//    virtual void updateAnimateWithNewAnimation(CCAnimation *newAnimation);
//    
//};

class Component : public CCSprite {
    
private:
    
    //动画间隔时间
    float m_fFrameAnimationInterval;
    
    //状态下标
    int m_nCurrentStateIndex;
    
    //Component对应的Animate类
    CCAnimate *m_pAnimate;
    
    CCArray *m_pFileNameArray;
    
private:
    
    CCAnimation *createAnimation(CCString *fileName);
    
public:
    
    Component(void);
    virtual ~Component(void);
    
    static Component *componentWithFileName(const char *fileName);
    
    virtual bool initWithFile(const char *fileName);
    
    
    /*
     *  组件的下一个状态
     */
    virtual void nextState(void);
    
    /*
     *  根据下标改变组件状态
     *  @param index 下标
     */
    virtual void stateByIndex(int index);
    
    /*
     *  设置组件的每个状态
     *  @param flieName 图片名字
     */
    virtual void setComponentStateWithFileName(const char *fileName);
    
    
    virtual void setFrameAnimationInterval(float frameAnimationInterval) {
        
        m_fFrameAnimationInterval = frameAnimationInterval;
    };
    
    virtual float getFrameAnimationInterval(void) {
        
        return m_fFrameAnimationInterval;
    };
    
    virtual void setCurrentStateIndex(int currentStateIndex) {
        
        m_nCurrentStateIndex = currentStateIndex;
    };
    
    virtual int getCurrentStateIndex(void) {
        
        return m_nCurrentStateIndex;
    };
    
    virtual void setComponentAnimate(CCAnimate *animate) {
        
        m_pAnimate = animate;
    };
    
    virtual CCAnimate *getAnimate(void) {
        
        return m_pAnimate;
    };
    
};

#endif /* defined(__Running_x__Component__) */
