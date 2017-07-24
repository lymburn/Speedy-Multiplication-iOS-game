//
//  ActionPerformer.cpp
//  Touch The Square
//
//  Created by Eugene Lu on 2017-07-11.
//
//

#include "ActionPerformer.hpp"

void ActionPerformer::fading(Node* target) {
    auto move1 = FadeOut::create(0.8);
    auto move2 = FadeIn::create(0.8);
    auto delay = DelayTime::create(2);
    auto seq = Sequence::create(move1, move2, delay, NULL);
    target->runAction(RepeatForever::create(seq));
}

void ActionPerformer::countDown(Label* target) {
    auto seq = Sequence::create(DelayTime::create(1), CallFunc::create([=]() {target->setString("2");}), DelayTime::create(1), CallFunc::create([=]() {target->setString("1");}), DelayTime::create(1), CallFunc::create([=]() {target->setString("START!");}), DelayTime::create(0.5), CallFunc::create([=]() {target->setVisible(false);}), NULL);
    target->runAction(seq);
}
