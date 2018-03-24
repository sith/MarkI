//
// Created by Fedorov, Alex on 2/2/18.
//

#include <environment/Environment.h>
#include "PrintState.h"

State *PrintState::execute() {
    return transitionFunction->nextState(EmptyStateValue::EMPTY_STATE_VALUE);
}

PrintState::PrintState() {}


void PrintState::setTransitionFunction(TransitionFunction<EmptyStateValue> &transitionFunction) {
    PrintState::transitionFunction = &transitionFunction;
}

PrintState::~PrintState() {}
