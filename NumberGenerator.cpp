//
//  NumberGenerator.cpp
//  Speedy Multiplication
//
//  Created by Eugene Lu on 2017-07-23.
//
//

#include "NumberGenerator.hpp"

NumberGenerator::NumberGenerator(Scene* playingScene) {
    currentScene = playingScene;
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    //Create all the answers needed up to 144
    for (int i = 0; i< 146; i++) {
        answers[i] = i;
        answerLabels[i] = Label::createWithTTF(std::to_string(i), "fonts/foo.ttf", 14);
    }
    
    //Create the question numbers needed up to 12
    for (int i = 0; i<14; i++) {
        questionNumbers[i] = i;
        questionLabels[i] = Label::createWithTTF(std::to_string(i), "fonts/foo.ttf", 14);
    }
}

void NumberGenerator::createQuestion() {
    srand(time(NULL));
    int firstNum = rand()%13;
    int secondNum = rand()%13;
    int product = firstNum * secondNum;
}
