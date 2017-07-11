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
    
private:
    Sprite* background;
    Scene* currentScene;
};


#endif /* ImageManager_hpp */
