//
// Created by Oleksandra Baukh on 1/20/18.
//

#include "DirectTransition.h"

State *DirectTransition::nextState(EmptyStateValue &stateValue) {
    return state;
}

DirectTransition::DirectTransition(State &state) : state(&state) {}
