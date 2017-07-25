//
//  NumberGenerator.cpp
//  Speedy Multiplication
//
//  Created by Eugene Lu on 2017-07-23.
//
//

#include "NumberGenerator.hpp"
#include <iostream>

NumberGenerator::NumberGenerator(Scene* playingScene) {
    currentScene = playingScene;
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    //Create all the answers needed up to 144 as well as 20 more numbers (for greater answers than 144)
    for (int i = 0; i < 165; i++) {
        answerLabels.push_back(Label::createWithTTF(std::to_string(i), "fonts/foo.ttf", 21));
        currentScene->addChild(answerLabels.at(i), 1);
        answerLabels.at(i)->setVisible(false);
        answerLabels.at(i)->setTextColor(Color4B::BLACK);
    }
    
    //Create the question numbers needed up to 12
    for (int i = 0; i<14; i++) {
        questionLabels.push_back(Label::createWithTTF(std::to_string(i), "fonts/foo.ttf", 21));
        currentScene->addChild(questionLabels.at(i),1);
        questionLabels.at(i)->setVisible(false);
        questionLabels.at(i)->setTextColor(Color4B::BLACK);
        
        questionLabels2.push_back(Label::createWithTTF(std::to_string(i), "fonts/foo.ttf", 21));
        currentScene->addChild(questionLabels2.at(i),1);
        questionLabels2.at(i)->setVisible(false);
        questionLabels2.at(i)->setTextColor(Color4B::BLACK);
    }
}

void NumberGenerator::createFirstQuestion() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    srand(time(NULL));
    firstNum = rand()%13;
    secondNum = rand()%13;
    product = firstNum * secondNum;
    
    questionLabels.at(firstNum)->setPosition(Vec2(visibleSize.width*0.35 + origin.x, visibleSize.height*0.8 + origin.y));
    questionLabels.at(firstNum)->setVisible(true);
    questionLabels2.at(secondNum)->setPosition(Vec2(visibleSize.width*0.65 + origin.x, visibleSize.height*0.8 + origin.y));
    questionLabels2.at(secondNum)->setVisible(true);
    
    //Create multiplication sign
    auto multSign = Label::createWithTTF("x", "fonts/foo.ttf", 16);
    multSign->setTextColor(Color4B::BLACK);
    multSign->setPosition(Vec2(visibleSize.width*0.5 + origin.x, visibleSize.height*0.8 + origin.y));
    currentScene->addChild(multSign,1);
}

void NumberGenerator::createFirstAnswers() {
    srand(time(NULL));
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    ans2 = product + rand()%19 + 1;
    ans3 = product + rand()%3 + 2;
    ans4 = rand()%165;
    
    if (ans4 == product) {
        ans4 + rand()%10 + 3; //Prevent have same answer twice
    }
    
    answerLabels.at(product)->setVisible(true); //Answer
    answerLabels.at(ans2)->setVisible(true); //Answer 2
    answerLabels.at(ans3)->setVisible(true); //Answer 3
    answerLabels.at(ans4)->setVisible(true); //Answer 4

    int quadrant = rand()%4; //Which quadrant the answer will be in
    
    if (quadrant == 0) {
        //Top left
        answerLabels.at(product)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans2)->setPosition(Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans3)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.35 + origin.y));
        answerLabels.at(ans4)->setPosition((Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.35 + origin.y)));
    } else if (quadrant == 1) {
        //Top right
        answerLabels.at(product)->setPosition(Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans2)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans3)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.35 + origin.y));
        answerLabels.at(ans4)->setPosition((Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.35 + origin.y)));
    } else if (quadrant == 2) {
        //Bottom right
        answerLabels.at(product)->setPosition(Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.35 + origin.y));
        answerLabels.at(ans2)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans3)->setPosition(Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans4)->setPosition((Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.35 + origin.y)));
    } else if (quadrant == 3) {
        //Bottom left
        answerLabels.at(product)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.35 + origin.y));
        answerLabels.at(ans2)->setPosition(Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans3)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans4)->setPosition((Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.35 + origin.y)));
    }
}
vector<Label*> NumberGenerator::getAnswerLabels() {
    return answerLabels;
}

vector<Label*> NumberGenerator::getQuestionLabels() {
    return questionLabels;
}

vector<Label*> NumberGenerator::getQuestionLabels2() {
    return questionLabels2;
}

void NumberGenerator::changeQuestionAndAnswer() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    //Set all the previous questions numbers to invisible
    questionLabels.at(firstNum)->setVisible(false);
    questionLabels2.at(secondNum)->setVisible(false);
    answerLabels.at(product)->setVisible(false);
    answerLabels.at(ans2)->setVisible(false);
    answerLabels.at(ans3)->setVisible(false);
    answerLabels.at(ans4)->setVisible(false);
    
    //New question numbers
    srand(time(NULL));
    firstNum = rand()%13;
    secondNum = rand()%13;
    product = firstNum * secondNum;
    
    questionLabels.at(firstNum)->setPosition(Vec2(visibleSize.width*0.35 + origin.x, visibleSize.height*0.8 + origin.y));
    questionLabels.at(firstNum)->setVisible(true);
    questionLabels2.at(secondNum)->setPosition(Vec2(visibleSize.width*0.65 + origin.x, visibleSize.height*0.8 + origin.y));
    questionLabels2.at(secondNum)->setVisible(true);
    
    //New answers
    ans2 = product + rand()%10 + 1;
    ans3 = rand()%product; //lower half or product
    ans4 = rand()%165; //upper half
    
    if (ans4 == product) {
        if (ans4++ != ans3) {
            ans4++;
        } else {
            ans4 += 2;
        }
    }
    
    answerLabels.at(product)->setVisible(true); //Answer
    answerLabels.at(ans2)->setVisible(true); //Answer 2
    answerLabels.at(ans3)->setVisible(true); //Answer 3
    answerLabels.at(ans4)->setVisible(true); //Answer 4
    
    int quadrant = rand()%4; //Which quadrant the answer will be in
    
    if (quadrant == 0) {
        //Top left
        answerLabels.at(product)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans2)->setPosition(Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans3)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.35 + origin.y));
        answerLabels.at(ans4)->setPosition((Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.35 + origin.y)));
    } else if (quadrant == 1) {
        //Top right
        answerLabels.at(product)->setPosition(Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans2)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans3)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.35 + origin.y));
        answerLabels.at(ans4)->setPosition((Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.35 + origin.y)));
    } else if (quadrant == 2) {
        //Bottom right
        answerLabels.at(product)->setPosition(Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.35 + origin.y));
        answerLabels.at(ans2)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans3)->setPosition(Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans4)->setPosition((Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.35 + origin.y)));
    } else if (quadrant == 3) {
        //Bottom left
        answerLabels.at(product)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.35 + origin.y));
        answerLabels.at(ans2)->setPosition(Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans3)->setPosition(Vec2(visibleSize.width*0.3 + origin.x, visibleSize.height*0.55 + origin.y));
        answerLabels.at(ans4)->setPosition((Vec2(visibleSize.width*0.7 + origin.x, visibleSize.height*0.35 + origin.y)));
    }

}
