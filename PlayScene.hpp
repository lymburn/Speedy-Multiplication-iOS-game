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
#include "SimpleAudioEngine.h"
#include <iostream>
using namespace std;

class PlayScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(PlayScene);
    void update(float);
    
private:
    Size buttonSize;
    bool tapped = false;
    bool gameStarted = false;
    bool gameEnded = false;
    int timeNumber = 0;
    float timeFloat = 0;
    int numOfQuestions = 20;
    int correct[20];
    int wrongAnswers = 0;
    Sprite* car;
    Sprite* checkMark;
    Sprite* cross;
    UserDefault* def = UserDefault::getInstance();
    CocosDenshion::SimpleAudioEngine* audio;
};

#endif /* PlayScene_hpp */
