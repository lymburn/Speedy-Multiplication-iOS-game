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
    
    //Create images and text
    auto ImageCreator = new ImageManager(this);
    ImageCreator->drawBackground();
    ImageCreator->drawChoicesButtons();
    
    auto TextCreator = new TextManager(this);
    TextCreator->createCountDown();
    TextCreator->writeTimeLabel();
    
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
