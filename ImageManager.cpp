//
//  ImageManager.cpp
//  Touch The Square
//
//  Created by Eugene Lu on 2017-07-11.
//
//

#include "ImageManager.hpp"
#include "ActionPerformer.hpp"
#include "PlayScene.hpp"
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
    questionScreen->setScale(2.7, 1.8);
    questionScreen->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height * 0.8 + origin.y));
    currentScene->addChild(questionScreen,1);
    
}

void ImageManager::drawCar() {
    car = Sprite::create("sprites/car.png");
    car->setPosition(Vec2(visibleSize.width * 0.22 + origin.x, visibleSize.height * 0.13 + origin.y));
    car->setScale(0.5,0.5);
    currentScene->addChild(car,1);
}

void ImageManager::drawMovedCar() {
    car = Sprite::create("sprites/car.png");
    car->setPosition(Vec2(visibleSize.width * 0.66 + origin.x, visibleSize.height * 0.13 + origin.y));
    car->setScale(0.5,0.5);
    currentScene->addChild(car,1);
}

void ImageManager::drawFlag() {
    flag = Sprite::create("sprites/flag.png");
    flag->setScale(1.5, 1.5);
    flag->setPosition(Vec2(visibleSize.width*0.8 + origin.x, visibleSize.height * 0.132 + origin.y));
    currentScene->addChild(flag,1);
}

void ImageManager::drawCheckMark() {
    checkmark = Sprite::create("sprites/checkmark.png");
    checkmark->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.68 + origin.y));
    checkmark->setScale(1.5,1.5);
    checkmark->setVisible(false);
    currentScene->addChild(checkmark,1);
}

void ImageManager::drawCross() {
    cross = Sprite::create("sprites/cross.png");
    cross->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.68 + origin.y));
    cross->setScale(1.5, 1.5);
    cross->setVisible(false);
    currentScene->addChild(cross,1);
}

void ImageManager::drawReplay() {
    //Replay button
    auto replayButton = Sprite::create("sprites/return.png");
    replayButton->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.35));
    replayButton->setScale(2, 2);
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [=](Touch* touch, Event* event) -> bool {
        
        auto bounds = event->getCurrentTarget()->getBoundingBox();
        
        if (bounds.containsPoint(touch->getLocation())){
            auto playScene = PlayScene::create();
            Director::getInstance()->replaceScene(playScene);
        }
        return true;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener,replayButton);
    currentScene->addChild(replayButton, 1);
}

Sprite* ImageManager::getCheckMark() {
    return checkmark;
}

Sprite* ImageManager::getCross() {
    return cross;
}

Size ImageManager::getButtonSize() {
    return buttons[0]->getContentSize();
}

Sprite* ImageManager::getQuestionScreen() {
    return questionScreen;
}

Sprite* ImageManager::getCar() {
    return car;
}




