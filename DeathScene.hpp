//
//  DeathScene.hpp
//  Speedy Multiplication
//
//  Created by Eugene Lu on 2017-08-16.
//
//

#ifndef DeathScene_hpp
#define DeathScene_hpp
USING_NS_CC;
#include <stdio.h>

class DeathScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    CREATE_FUNC(DeathScene);
    
private:
    UserDefault* def = UserDefault::getInstance();
};

#endif /* DeathScene_hpp */
