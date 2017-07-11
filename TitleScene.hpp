//
//  TitleScene.hpp
//  TapGame
//
//  Created by Eugene Lu on 2017-07-11.
//
//

#ifndef TitleScene_hpp
#define TitleScene_hpp
USING_NS_CC;
#include <stdio.h>

class TitleScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(TitleScene);
};

#endif /* TitleScene_hpp */
