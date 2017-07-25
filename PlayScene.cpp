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
    
    auto TextCreator = new TextManager(this);
    TextCreator->createCountDown();
    TextCreator->writeTimeLabel();
    
    //Numbers
    auto NumberManager = new NumberGenerator(this);
    NumberManager->createFirstQuestion();
    NumberManager->createFirstAnswers();
    
    //Pressing the 4 buttons
    buttonSize = ImageCreator->getButtonSize();
    auto buttonListener = EventListenerTouchOneByOne::create();
    buttonListener->setSwallowTouches(true);
    buttonListener->onTouchBegan = [=](Touch* touch, Event* event){
        return true;
    };
    
    buttonListener->onTouchEnded = [=](Touch* touch, Event* event) {
        //In order of top left, top right, bottom right, bottom left
        if ((touch->getLocation().x >= visibleSize.width*0.3 - buttonSize.width/2 + origin.x) && (touch->getLocation().x <= visibleSize.width*0.3 + origin.x + buttonSize.width/2) && (touch->getLocation().y >= visibleSize.height*0.55 - buttonSize.height/2 + origin.y) && (touch->getLocation().y <= visibleSize.height*0.55 + buttonSize.height/2 + origin.y)) {
            NumberManager->changeQuestionAndAnswer();
        } else if ((touch->getLocation().x >= visibleSize.width*0.7 - buttonSize.width/2 + origin.x) && (touch->getLocation().x <= visibleSize.width*0.7 + origin.x + buttonSize.width/2) && (touch->getLocation().y >= visibleSize.height*0.55 - buttonSize.height/2 + origin.y) && (touch->getLocation().y <= visibleSize.height*0.55 + buttonSize.height/2 + origin.y)) {
            log ("touch top right");
        } else if ((touch->getLocation().x >= visibleSize.width*0.7 - buttonSize.width/2 + origin.x) && (touch->getLocation().x <= visibleSize.width*0.7 + origin.x + buttonSize.width/2) && (touch->getLocation().y >= visibleSize.height*0.35 - buttonSize.height/2 + origin.y) && (touch->getLocation().y <= visibleSize.height*0.35 + buttonSize.height/2 + origin.y)) {
            log ("touch bottom right");
        } else if ((touch->getLocation().x >= visibleSize.width*0.3 - buttonSize.width/2 + origin.x) && (touch->getLocation().x <= visibleSize.width*0.3 + origin.x + buttonSize.width/2) && (touch->getLocation().y >= visibleSize.height*0.35 - buttonSize.height/2 + origin.y) && (touch->getLocation().y <= visibleSize.height*0.35 + buttonSize.height/2 + origin.y)) {
            log("touch bottom left");
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

void PlayScene::changeQuestionAndAnswers() {
    
}
