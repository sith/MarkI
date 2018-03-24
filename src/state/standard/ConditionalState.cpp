//
// Created by Oleksandra Baukh on 2/17/18.
//

#include "ConditionalState.h"

State *ConditionalState::execute() {
    return readyForNextState() ? transitionFunction->nextState(EmptyStateValue::EMPTY_STATE_VALUE) : this;

}
