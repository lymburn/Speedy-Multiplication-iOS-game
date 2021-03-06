//
//  NumberGenerator.hpp
//  Speedy Multiplication
//
//  Created by Eugene Lu on 2017-07-23.
//
//

#ifndef NumberGenerator_hpp
#define NumberGenerator_hpp
USING_NS_CC;
#include <stdio.h>
using namespace std;

#endif /* NumberGenerator_hpp */

class NumberGenerator {
public:
    NumberGenerator(Scene* playingScene);
    void createFirstQuestion();
    void createFirstAnswers();
    void changeQuestionAndAnswer();
    void clearAllNumbers();
    int getCorrectQuadrant();

private:
    Size visibleSize;
    Vec2 origin;
    int firstNum;
    int secondNum;
    int product;
    int ans2, ans3, ans4;
    int quadrant;
    vector<Label*> answerLabels;
    vector<Label*> questionLabels;
    vector<Label*> questionLabels2;
    Scene* currentScene;
};
