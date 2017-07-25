//
//  ImageManager.cpp
//  Touch The Square
//
//  Created by Eugene Lu on 2017-07-11.
//
//

#include "ImageManager.hpp"
ImageManager::ImageManager(Scene* playingScene) {
    currentScene = playingScene;
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
}

void ImageManager::drawBackground() {
    
    background = Sprite::create("backgrounds/background.png");
    background -> setAnchorPoint(Vec2(0,0));
    background->setPosition(Vec2(origin.x,origin.y));
    background->setScale(visibleSize.width/background->getContentSize().width, visibleSize.height/background->getContentSize().height);
    currentScene->addChild(background,0);
}

void ImageManager::drawChoicesButtons() {
    //4 buttons for choices
    for (int i = 0; i < 4; i++) {
        buttons[i] = Sprite::create("sprites/button.png");
        buttons[i] ->setScale(1.2, 1.5);
    }
    
    buttons[0]->setPosition(Vec2(visibleSize.width * 0.3 + origin.x, visibleSize.height * 0.55 + origin.y)); //top left
    buttons[1]->setPosition(Vec2(visibleSize.width * 0.7 + origin.x, visibleSize.height * 0.55 + origin.y)); // top right
    buttons[2]->setPosition(Vec2(visibleSize.width * 0.3 + origin.x, visibleSize.height * 0.35 + origin.y)); //bottom left
    buttons[3]->setPosition(Vec2(visibleSize.width * 0.7 + origin.x, visibleSize.height * 0.35 + origin.y)); //bottom right
    
    for (int i = 0; i<4; i++) {
        currentScene->addChild(buttons[i],1);
    }
    
    questionScreen = Sprite::create("sprites/button.png");
    questionScreen->setScale(3, 1.8);
    questionScreen->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.8 + origin.y));
    currentScene->addChild(questionScreen,1);
    
}

Size ImageManager::getButtonSize() {
    return buttons[0]->getContentSize();
}


