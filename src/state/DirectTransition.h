//
// Created by Oleksandra Baukh on 1/20/18.
//

#ifndef MARK1_DIRECTTRANSITION_H
#define MARK1_DIRECTTRANSITION_H


#include "State.h"

class DirectTransition : public TransitionFunction<EmptyStateValue> {
    State *state;
public:
    DirectTransition(State &state);
public:

    State *nextState(EmptyStateValue &stateValue) override;
};


#endif //MARK1_DIRECTTRANSITION_H
