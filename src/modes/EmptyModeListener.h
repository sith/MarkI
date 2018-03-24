//
// Created by Oleksandra Baukh on 1/17/18.
//

#ifndef MARK1_EMPTYMODELISTENER_H
#define MARK1_EMPTYMODELISTENER_H


#include "ModeListener.h"

class EmptyModeListener : public ModeListener{
public:
    virtual void onModeChange(ModeName mode);
};


#endif //MARK1_EMPTYMODELISTENER_H
