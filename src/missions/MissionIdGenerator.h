//
// Created by Fedorov, Alex on 2/28/18.
//

#ifndef MARKOS_MISSIONIDGENERATOR_H
#define MARKOS_MISSIONIDGENERATOR_H

#include <types.h>

class MissionIdGenerator {
    virtual uint8 nextId()= 0;
};

#endif //MARKOS_MISSIONIDGENERATOR_H
