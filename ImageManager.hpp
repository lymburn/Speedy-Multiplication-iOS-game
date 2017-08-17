//
//  ImageManager.hpp
//  Touch The Square
//
//  Created by Eugene Lu on 2017-07-11.
//
//

#ifndef ImageManager_hpp
#define ImageManager_hpp
USING_NS_CC;
#include <stdio.h>

class ImageManager {
public:
    ImageManager(Scene* playingScene);
    void drawBackground();
    void drawChoicesButtons();
    void drawCar();
    void drawMovedCar();
    void drawFlag();
    void drawCheckMark();
    void drawCross();
    void drawReplay();
    Sprite* getCheckMark();
    Sprite* getCross();
    Sprite* getQuestionScreen();
    Size getButtonSize();
    Sprite* getCar();
    
private:
    Size visibleSize;
    Vec2 origin;
    Sprite* buttons[4];
    Sprite* questionScreen;
    Sprite* background;
    Sprite* car;
    Sprite* flag;
    Sprite* checkmark;
    Sprite* cross;
    Scene* currentScene;
};


#endif /* ImageManager_hpp */
