//
//  PlayScene.hpp
//  Touch The Square
//
//  Created by Eugene Lu on 2017-07-11.
//
//

#ifndef PlayScene_hpp
#define PlayScene_hpp
USING_NS_CC;
#include <stdio.h>

class PlayScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(PlayScene);
    void update(float);
    
private:
    bool gameStarted = false;
    bool gameEnded = false;
    int timeNumber = 0;
    float timeFloat = 0;
};

#endif /* PlayScene_hpp */
