//
// Created by Fedorov, Alex on 2/28/18.
//

#ifndef MARKOS_RANDOMMISSIONIDGENERATOR_H
#define MARKOS_RANDOMMISSIONIDGENERATOR_H


#include <Random.h>
#include "missions/MissionIdGenerator.h"

class RandomMissionIdGenerator : public MissionIdGenerator {
    Random &random;
public:
    RandomMissionIdGenerator(Random &random);

    uint8 nextId() override;
};


#endif //MARKOS_RANDOMMISSIONIDGENERATOR_H
