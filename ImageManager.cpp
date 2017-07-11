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
}

void ImageManager::drawBackground() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    background = Sprite::create("backgrounds/background.png");
    background -> setAnchorPoint(Vec2(0,0));
    background->setPosition(Vec2(origin.x,origin.y));
    background->setScale(visibleSize.width/background->getContentSize().width, visibleSize.height/background->getContentSize().height);
    currentScene->addChild(background,0);
}


