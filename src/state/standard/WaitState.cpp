#include <environment/Environment.h>
#include "WaitState.h"

State *WaitState::execute() {
    switch (stateStatus) {
        case StateStatus::WAITING:
            Environment::getEnvironment().getTimer().addTimer(waitTime, *this);
            stateStatus = StateStatus::IN_PROGRESS;
            return this;
        case StateStatus::IN_PROGRESS:
            return this;
        case StateStatus::DONE:
            stateStatus = StateStatus::WAITING;
            return transitionFunction->nextState(EmptyStateValue::EMPTY_STATE_VALUE);
    }
    return this;
}

void WaitState::onEvent() {
    stateStatus = StateStatus::DONE;
}

WaitState::WaitState(int waitTime) : waitTime(waitTime) {}

void WaitState::setTransitionFunction(TransitionFunction<EmptyStateValue> &transitionFunction) {
    WaitState::transitionFunction = &transitionFunction;
}

void WaitState::stop() {
    State::stop();
    Environment::getEnvironment().getTimer().removeTasksForListener(*this);
}

WaitState::~WaitState() {}
