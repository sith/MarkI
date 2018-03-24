//
// Created by Fedorov, Alex on 2/2/18.
//

#ifndef MARKOS_WAITSTATE_H
#define MARKOS_WAITSTATE_H


#include <state/State.h>
#include <logger/Logger.h>

class WaitState : public State, public TimerListener {
    int waitTime;
    TransitionFunction<EmptyStateValue> *transitionFunction;
public:
    void setTransitionFunction(TransitionFunction<EmptyStateValue> &transitionFunction);

    WaitState(int waitTime);

    void onEvent() override;

    State *execute() override;

    void stop() override;

    virtual ~WaitState();
};


#endif //MARKOS_WAITSTATE_H
