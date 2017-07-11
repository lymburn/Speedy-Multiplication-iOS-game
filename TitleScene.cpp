//
//  TitleScene.cpp
//  TapGame
//
//  Created by Eugene Lu on 2017-07-11.
//
//

#include "TitleScene.hpp"
#include "ImageManager.hpp"

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
    
    //Create images
    auto ImageCreator = new ImageManager(this);
    ImageCreator->drawBackground();
    
    return true;
}

