//
//  TitleScene.cpp
//  TapGame
//
//  Created by Eugene Lu on 2017-07-11.
//
//

#include "TitleScene.hpp"
#include "ImageManager.hpp"
#include "TextManager.hpp"
#include "PlayScene.hpp"

Scene* TitleScene::createScene()
{
    return TitleScene::create();
}

bool TitleScene::init()
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
    
    auto TextCreator = new TextManager(this);
    TextCreator->writeTitleAndTap();
    
    //Move to play scene after tapping down
    auto titleTapListener = EventListenerTouchOneByOne::create();
    titleTapListener->setSwallowTouches(true);
    // trigger when you push down
    
    titleTapListener->onTouchBegan = [=](Touch* touch, Event* event){
        auto playScene = PlayScene::createScene();
        Director::getInstance()->replaceScene(playScene);
        return true; // if you are consuming it
    };
    
    // Add listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(titleTapListener, this);
    
    delete ImageCreator;
    delete TextCreator;
    return true;
}

