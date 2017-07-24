//
//  TextManager.cpp
//  Touch The Square
//
//  Created by Eugene Lu on 2017-07-11.
//
//

#include "TextManager.hpp"
#include "ActionPerformer.hpp"

TextManager::TextManager(Scene* playingScene) {
    currentScene = playingScene;
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
}

void TextManager::writeTitleAndTap() {
    ActionPerformer PerformActions;
    
    auto speedy = Label::createWithTTF("SPEEDY", "fonts/foo.ttf", 30);
    auto mult = Label::createWithTTF("MULTIPLICATION", "fonts/foo.ttf",20);
    auto example = Label::createWithTTF("a x b = c", "fonts/foo.ttf", 18);
    auto tapToPlay = Label::createWithTTF("TAP TO PLAY", "fonts/foo.ttf", 12);
    
    speedy->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.75));
    mult->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.75 - speedy->getContentSize().height));
    example->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.4));
    tapToPlay->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.2));
    
    currentScene->addChild(speedy);
    currentScene->addChild(mult);
    currentScene->addChild(example);
    currentScene->addChild(tapToPlay);
    
    PerformActions.fading(tapToPlay);
}

void TextManager::createCountDown() {
    ActionPerformer PerformActions;
    auto number = Label::createWithTTF("3", "fonts/foo.ttf", 10);
    number->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.2));
    currentScene->addChild(number,1);
    PerformActions.countDown(number);
}

void TextManager::writeTimeLabel() {
    timeLabel = Label::createWithTTF("Time: ", "fonts/foo.ttf", 12);
    timeLabel->setPosition(Vec2(visibleSize.width*0.7 + origin.x, origin.y + timeLabel->getContentSize().height));
    currentScene->addChild(timeLabel, 1);
}
