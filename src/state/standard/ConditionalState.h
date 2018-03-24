//
// Created by Oleksandra Baukh on 2/17/18.
//

#ifndef MARKOS_CONDITIONALSTATE_H
#define MARKOS_CONDITIONALSTATE_H


#include <state/State.h>

class ConditionalState : public State {
    TransitionFunction<EmptyStateValue> *transitionFunction;
public:
    State *execute() override;

    virtual bool readyForNextState()= 0;
};


#endif //MARKOS_CONDITIONALSTATE_H
