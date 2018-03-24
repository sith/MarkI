//
// Created by Fedorov, Alex on 2/2/18.
//

#ifndef MARKOS_PRINTSTATE_H
#define MARKOS_PRINTSTATE_H

#include <state/State.h>
#include <logger/Logger.h>
#include <memory/Pointer.h>

class PrintState : public State {
    TransitionFunction<EmptyStateValue> *transitionFunction;
public:
    PrintState();

    void setTransitionFunction(TransitionFunction<EmptyStateValue> &transitionFunction);

    virtual ~PrintState();

    State *execute() override;

};


#endif //MARKOS_PRINTSTATE_H
