//
//  DeathScene.cpp
//  Speedy Multiplication
//
//  Created by Eugene Lu on 2017-08-16.
//
//

#include "DeathScene.hpp"
#include "ImageManager.hpp"
#include "TextManager.hpp"

Scene* DeathScene::createScene()
{
    return DeathScene::create();
}

bool DeathScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto ImageCreator = new ImageManager(this);
    ImageCreator->drawBackground();
    ImageCreator->drawFlag();
    ImageCreator->drawMovedCar();
    ImageCreator->drawReplay();
    
    
    auto TextCreator = new TextManager(this);
    TextCreator->writeResults();
    
    
    delete ImageCreator;

    return true;
}
