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
    auto number = Label::createWithTTF("3", "fonts/foo.ttf", 16);
    number->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.22));
    number->setTextColor(Color4B::BLACK);
    currentScene->addChild(number,1);
    PerformActions.countDown(number);
}

void TextManager::writeNumOfQuestions(int numOfQuestions) {
    numQuestions = Label::createWithTTF(std::to_string(numOfQuestions), "fonts/foo.ttf", 11);
    numQuestions->setPosition(Vec2(visibleSize.width*0.5 + origin.x, visibleSize.height*0.95 + origin.y));
    numQuestions->setTextColor(Color4B::BLACK);
    currentScene->addChild(numQuestions,1);
    
    questionsRemaining = Label::createWithTTF("Questions left: ", "fonts/foo.ttf", 11);
    questionsRemaining->setPosition(Vec2(questionsRemaining->getContentSize().width*0.6 + origin.x, visibleSize.height*0.95 + origin.y));
    questionsRemaining->setTextColor(Color4B::BLACK);
    currentScene->addChild(questionsRemaining,1);
}

Label* TextManager::getNumQuestions() {
    return numQuestions;
}

void TextManager::writeResults() {
    ActionPerformer PerformActions;
    auto congrats = Label::createWithTTF("CONGRATS!", "fonts/foo.ttf",28);
    auto timeLabel = Label::createWithTTF("Time: ", "fonts/foo.ttf", 18);
    auto timeNumber = Label::createWithTTF(std::to_string(def->getIntegerForKey("time")), "fonts/foo.ttf", 18);
    auto accuracy = Label::createWithTTF("Accuracy: ", "fonts/foo.ttf", 18);
    auto accuracyNum = Label::createWithTTF(std::to_string(def->getIntegerForKey("accuracy")), "fonts/foo.ttf", 18);
    auto percent = Label::createWithTTF("%", "fonts/foo.ttf", 18);
    
    congrats->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.8 + origin.y));
    timeLabel->setAnchorPoint(Vec2(0,0.5));
    timeLabel->setPosition(Vec2(visibleSize.width*0.15 + origin.x, visibleSize.height*0.65 + origin.y));
    timeNumber->setPosition(Vec2(visibleSize.width*0.47 + origin.x, visibleSize.height*0.65 + origin.y));
    accuracy->setAnchorPoint(Vec2(0,0.5));
    accuracy->setPosition(Vec2(visibleSize.width*0.15 + origin.x, visibleSize.height*0.5 + origin.y));
    accuracyNum->setPosition(Vec2(visibleSize.width*0.75 + origin.x, visibleSize.height*0.5 + origin.y));
    percent->setPosition(Vec2(visibleSize.width*0.8 + percent->getContentSize().width + origin.x, visibleSize.height*0.5 + origin.y));
    
    currentScene->addChild(congrats);
    currentScene->addChild(timeLabel,1);
    currentScene->addChild(timeNumber,1);
    currentScene->addChild(accuracy,1);
    currentScene->addChild(accuracyNum,1);
    currentScene->addChild(percent,1);
}

