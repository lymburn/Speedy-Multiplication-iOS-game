//
//  PlayScene.cpp
//  Touch The Square
//
//  Created by Eugene Lu on 2017-07-11.
//
//

#include "PlayScene.hpp"
#include "ImageManager.hpp"
#include "TextManager.hpp"
#include "NumberGenerator.hpp"

Scene* PlayScene::createScene()
{
    return PlayScene::create();
}

bool PlayScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    //Create images and text
    auto ImageCreator = new ImageManager(this);
    ImageCreator->drawBackground();
    ImageCreator->drawChoicesButtons();
    ImageCreator->drawCar();
    
    auto TextCreator = new TextManager(this);
    TextCreator->createCountDown();
    
    //Numbers
    auto NumberManager = new NumberGenerator(this);
    NumberManager->createFirstQuestion();
    NumberManager->createFirstAnswers();
    
    //Pressing the 4 buttons
    auto questionScreen = ImageCreator->getQuestionScreen(); //Use screen to have callback and prevent double tapping on the buttons
    buttonSize = ImageCreator->getButtonSize();
    auto buttonListener = EventListenerTouchOneByOne::create();
    buttonListener->setSwallowTouches(true);
    buttonListener->onTouchBegan = [=](Touch* touch, Event* event){
        return true;
    };
    
    buttonListener->onTouchEnded = [=](Touch* touch, Event* event) {
        if (tapped == false && gameStarted) {
            //In order of top left, top right, bottom right, bottom left (quadrant 0, 1, 2, 3)
            //If touch corresponds to the quadrant with the correct answer, moves on to the next answer. Else, notify the user and tells them to retry.
            if ((touch->getLocation().x >= visibleSize.width*0.3 - buttonSize.width/2 + origin.x) && (touch->getLocation().x <= visibleSize.width*0.3 + origin.x + buttonSize.width/2) && (touch->getLocation().y >= visibleSize.height*0.55 - buttonSize.height/2 + origin.y) && (touch->getLocation().y <= visibleSize.height*0.55 + buttonSize.height/2 + origin.y)) {
                if (NumberManager->getCorrectQuadrant() == 0) {
                    NumberManager->changeQuestionAndAnswer();
                }
            } else if ((touch->getLocation().x >= visibleSize.width*0.7 - buttonSize.width/2 + origin.x) && (touch->getLocation().x <= visibleSize.width*0.7 + origin.x + buttonSize.width/2) && (touch->getLocation().y >= visibleSize.height*0.55 - buttonSize.height/2 + origin.y) && (touch->getLocation().y <= visibleSize.height*0.55 + buttonSize.height/2 + origin.y)) {
                if (NumberManager->getCorrectQuadrant() == 1) {
                    NumberManager->changeQuestionAndAnswer();
                }
            } else if ((touch->getLocation().x >= visibleSize.width*0.7 - buttonSize.width/2 + origin.x) && (touch->getLocation().x <= visibleSize.width*0.7 + origin.x + buttonSize.width/2) && (touch->getLocation().y >= visibleSize.height*0.35 - buttonSize.height/2 + origin.y) && (touch->getLocation().y <= visibleSize.height*0.35 + buttonSize.height/2 + origin.y)) {
                if (NumberManager->getCorrectQuadrant() == 2) {
                    NumberManager->changeQuestionAndAnswer();
                }
            } else if ((touch->getLocation().x >= visibleSize.width*0.3 - buttonSize.width/2 + origin.x) && (touch->getLocation().x <= visibleSize.width*0.3 + origin.x + buttonSize.width/2) && (touch->getLocation().y >= visibleSize.height*0.35 - buttonSize.height/2 + origin.y) && (touch->getLocation().y <= visibleSize.height*0.35 + buttonSize.height/2 + origin.y)) {
                if (NumberManager->getCorrectQuadrant() == 3) {
                    NumberManager->changeQuestionAndAnswer();
                }
            }
        }
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(buttonListener, this);
    
    
    this->scheduleUpdate();
    
    delete ImageCreator;
    delete TextCreator;
    return true;
}

void PlayScene::update(float delta) {
    timeNumber++;
    timeFloat = static_cast<float>(timeNumber)/60;
    
    if (timeFloat == 3.5) {
        gameStarted = true;
    }
}

