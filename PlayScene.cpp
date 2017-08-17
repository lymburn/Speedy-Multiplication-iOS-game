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
#include "DeathScene.hpp"

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
    //Audio
    audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->setEffectsVolume(4.0f);
    //Sizes
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    //Reset time and accuracy
    def->setIntegerForKey("time", 0);
    for (int i = 0; i < 20; i++) {
        correct[i] = 0; //0 for correct, 1 for wrong
    }
    //Create images and text
    auto ImageCreator = new ImageManager(this);
    ImageCreator->drawBackground();
    ImageCreator->drawChoicesButtons();
    ImageCreator->drawCar();
    ImageCreator->drawFlag();
    ImageCreator->drawCheckMark();
    ImageCreator->drawCross();
    car = ImageCreator->getCar();
    checkMark = ImageCreator->getCheckMark();
    cross = ImageCreator->getCross();
    
    auto TextCreator = new TextManager(this);
    TextCreator->createCountDown();
    TextCreator->writeNumOfQuestions(numOfQuestions);
    Label* numQuestions = TextCreator->getNumQuestions(); //Get the label displaying number of questions left
    
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
        if (tapped == false && gameStarted && !gameEnded) {
            //In order of top left, top right, bottom right, bottom left (quadrant 0, 1, 2, 3)
            //If touch corresponds to the quadrant with the correct answer, moves on to the next answer. Else, notify the user and tells them to retry.
            if ((touch->getLocation().x >= visibleSize.width*0.3 - buttonSize.width/2 + origin.x) && (touch->getLocation().x <= visibleSize.width*0.3 + origin.x + buttonSize.width/2) && (touch->getLocation().y >= visibleSize.height*0.55 - buttonSize.height/2 + origin.y) && (touch->getLocation().y <= visibleSize.height*0.55 + buttonSize.height/2 + origin.y)) {
                if (NumberManager->getCorrectQuadrant() == 0 && numOfQuestions >= 0) {
                    audio->playEffect("music/correct.mp3", false, 1.0f, 1.0f, 1.0f);
                    NumberManager->changeQuestionAndAnswer();
                    checkMark->runAction(Sequence::create(CallFunc::create([=](){checkMark->setVisible(true);}), DelayTime::create(0.5), CallFunc::create([=](){checkMark->setVisible(false);}), NULL)); //Checkmark appears for 0.5 sec
                    cross->setVisible(false);//Dont show cross
                    car->runAction(MoveBy::create(1,Vec2((visibleSize.width*0.46)/20,0))); //Move car every correct answer
                    numOfQuestions--; //Decrease the number of questions left until 0
                    numQuestions->setString(std::to_string(numOfQuestions));
                    correct[20-numOfQuestions] = 0; //Set the number in the answers array to correct(0)
                } else { //If wrong
                    audio->playEffect("music/wrong.mp3", false, 1.0f, 1.0f, 1.0f);
                    cross->runAction(Sequence::create(CallFunc::create([=](){cross->setVisible(true);}), DelayTime::create(0.5), CallFunc::create([=](){cross->setVisible(false);}), NULL));
                    checkMark->setVisible(false);
                    correct[20-numOfQuestions] = 1;//Set question response to incorrect (lower accuracy)
                }
            } else if ((touch->getLocation().x >= visibleSize.width*0.7 - buttonSize.width/2 + origin.x) && (touch->getLocation().x <= visibleSize.width*0.7 + origin.x + buttonSize.width/2) && (touch->getLocation().y >= visibleSize.height*0.55 - buttonSize.height/2 + origin.y) && (touch->getLocation().y <= visibleSize.height*0.55 + buttonSize.height/2 + origin.y)) {
                if (NumberManager->getCorrectQuadrant() == 1 && numOfQuestions >= 0) {
                    audio->playEffect("music/correct.mp3", false, 1.0f, 1.0f, 1.0f);
                    NumberManager->changeQuestionAndAnswer();
                    checkMark->runAction(Sequence::create(CallFunc::create([=](){checkMark->setVisible(true);}), DelayTime::create(0.5), CallFunc::create([=](){checkMark->setVisible(false);}), NULL));
                    cross->setVisible(false);
                    car->runAction(MoveBy::create(1,Vec2((visibleSize.width*0.46)/20,0)));
                    numOfQuestions--;
                    numQuestions->setString(std::to_string(numOfQuestions));
                    correct[20-numOfQuestions] = 0;
                } else {
                    audio->playEffect("music/wrong.mp3", false, 1.0f, 1.0f, 1.0f);
                    cross->runAction(Sequence::create(CallFunc::create([=](){cross->setVisible(true);}), DelayTime::create(0.5), CallFunc::create([=](){cross->setVisible(false);}), NULL));
                    checkMark->setVisible(false);
                    correct[20-numOfQuestions] = 1;
                }
            } else if ((touch->getLocation().x >= visibleSize.width*0.7 - buttonSize.width/2 + origin.x) && (touch->getLocation().x <= visibleSize.width*0.7 + origin.x + buttonSize.width/2) && (touch->getLocation().y >= visibleSize.height*0.35 - buttonSize.height/2 + origin.y) && (touch->getLocation().y <= visibleSize.height*0.35 + buttonSize.height/2 + origin.y)) {
                if (NumberManager->getCorrectQuadrant() == 2 && numOfQuestions >= 0) {
                    audio->playEffect("music/correct.mp3", false, 1.0f, 1.0f, 1.0f);
                    NumberManager->changeQuestionAndAnswer();
                    checkMark->runAction(Sequence::create(CallFunc::create([=](){checkMark->setVisible(true);}), DelayTime::create(0.5), CallFunc::create([=](){checkMark->setVisible(false);}), NULL));
                    cross->setVisible(false);
                    car->runAction(MoveBy::create(1,Vec2((visibleSize.width*0.46)/20,0)));
                    numOfQuestions--;
                    numQuestions->setString(std::to_string(numOfQuestions));
                    correct[20-numOfQuestions] = 0;
                } else {
                    audio->playEffect("music/wrong.mp3", false, 1.0f, 1.0f, 1.0f);
                    cross->runAction(Sequence::create(CallFunc::create([=](){cross->setVisible(true);}), DelayTime::create(0.5), CallFunc::create([=](){cross->setVisible(false);}), NULL));
                    checkMark->setVisible(false);
                    correct[20-numOfQuestions] = 1;
                }
            } else if ((touch->getLocation().x >= visibleSize.width*0.3 - buttonSize.width/2 + origin.x) && (touch->getLocation().x <= visibleSize.width*0.3 + origin.x + buttonSize.width/2) && (touch->getLocation().y >= visibleSize.height*0.35 - buttonSize.height/2 + origin.y) && (touch->getLocation().y <= visibleSize.height*0.35 + buttonSize.height/2 + origin.y)) {
                if (NumberManager->getCorrectQuadrant() == 3 && numOfQuestions >= 0) {
                    audio->playEffect("music/correct.mp3", false, 1.0f, 1.0f, 1.0f);
                    NumberManager->changeQuestionAndAnswer();
                    checkMark->runAction(Sequence::create(CallFunc::create([=](){checkMark->setVisible(true);}), DelayTime::create(0.5), CallFunc::create([=](){checkMark->setVisible(false);}), NULL));
                    cross->setVisible(false);
                    car->runAction(MoveBy::create(1,Vec2((visibleSize.width*0.46)/20,0)));
                    numOfQuestions--;
                    numQuestions->setString(std::to_string(numOfQuestions));
                    correct[20-numOfQuestions] = 0;
                } else {
                    audio->playEffect("music/wrong.mp3", false, 1.0f, 1.0f, 1.0f);
                    cross->runAction(Sequence::create(CallFunc::create([=](){cross->setVisible(true);}), DelayTime::create(0.5), CallFunc::create([=](){cross->setVisible(false);}), NULL));
                    checkMark->setVisible(false);
                    correct[20-numOfQuestions] = 1;
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
    def->setIntegerForKey("time", round(timeFloat));
    def->flush();
    
    if (timeFloat == 3.5) {
        gameStarted = true;
    }
    
    if (numOfQuestions == 0) {
        gameStarted = false;
        gameEnded = true;
        wrongAnswers = 0;
    }
    
    if (gameEnded) {
        for (int i = 0; i<20; i++) {
            if (correct[i] == 1) {
                wrongAnswers++;
            }
        }
        def->setIntegerForKey("accuracy", ((20-wrongAnswers)/20.0)*100);
        auto deathScene = DeathScene::createScene();
        Director::getInstance()->replaceScene(deathScene);
    }
}

