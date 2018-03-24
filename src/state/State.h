//
// Created by Oleksandra Baukh on 1/10/18.
//

#ifndef MARKOS_STATE_H
#define MARKOS_STATE_H

template<class T>
class TransitionFunction;

enum class StateStatus {
    WAITING,
    IN_PROGRESS,
    DONE,

};

class State {
protected:
    StateStatus stateStatus = StateStatus::WAITING;
public:
    virtual ~State() {}

    virtual State *execute()= 0;

    virtual void stop() {
        stateStatus = StateStatus::WAITING;
    };
};

class EmptyStateValue {
public:
    static EmptyStateValue EMPTY_STATE_VALUE;
};


template<class T>
class TransitionFunction {
public:
    virtual State *nextState(T &stateValue)= 0;
};


#endif //MARKOS_STATE_H
