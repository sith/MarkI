//
// Created by Oleksandra Baukh on 1/17/18.
//

#ifndef MARK1_MODELISTENER_H
#define MARK1_MODELISTENER_H

#include "ModeName.h"
#include "Mode.h"

class ModeListener {
public:
    virtual void onModeChange(ModeName mode)= 0;
};

#endif //MARK1_MODELISTENER_H
