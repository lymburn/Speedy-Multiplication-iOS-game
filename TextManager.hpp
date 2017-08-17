//
//  TextManager.hpp
//  Touch The Square
//
//  Created by Eugene Lu on 2017-07-11.
//
//

#ifndef TextManager_hpp
#define TextManager_hpp
USING_NS_CC;

#include <stdio.h>

class TextManager {
public:
    TextManager(Scene* playingScene);
    void writeTitleAndTap();
    void getTimeLabel();
    void createCountDown();
    void writeNumOfQuestions(int numOfQuestions);
    Label* getNumQuestions();
    void writeResults();
private:
    Size visibleSize;
    Vec2 origin;
    Scene* currentScene;
    Label* timeLabel;
    Label* questionsRemaining;
    Label* numQuestions;
    UserDefault* def = UserDefault::getInstance();
};

#endif /* TextManager_hpp */
