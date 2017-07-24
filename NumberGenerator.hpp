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

#endif /* NumberGenerator_hpp */

class NumberGenerator {
public:
    NumberGenerator(Scene* playingScene);
    void createQuestion();
private:
    Size visibleSize;
    Vec2 origin;
    int answers[145];
    Label* answerLabels[145];
    int questionNumbers[13];
    Label* questionLabels[13];
    Scene* currentScene;
};
