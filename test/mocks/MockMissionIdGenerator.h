//
// Created by Fedorov, Alex on 2/28/18.
//

#ifndef MARKOS_MOCKMISSIONIDGENERATOR_H
#define MARKOS_MOCKMISSIONIDGENERATOR_H

#include "gmock/gmock.h"
#include "missions/MissionIdGenerator.h"

class MockMissionIdGenerator : public MissionIdGenerator {
public:
    MOCK_METHOD0(nextId,
                 uint8());
};

#endif //MARKOS_MOCKMISSIONIDGENERATOR_H
