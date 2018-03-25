//
// Created by Oleksandra Baukh on 3/25/18.
//

#ifndef MARKOS_MAIN_MOCKMISSIONMANAGER_H
#define MARKOS_MAIN_MOCKMISSIONMANAGER_H

#include <missions/MissionManager.h>
#include "gmock/gmock.h"

class MockMissionManager : public MissionManager {
public:
    MOCK_METHOD0(recordMission,
                 void());

    MOCK_METHOD0(stopMissionRecording,
                 void());

    MOCK_METHOD0(stopMissionReplay,
                 void());
    MOCK_METHOD1(recordMission,
                 void(int8
                         id));

    MOCK_METHOD0(replayLastMission,
                 void());
    MOCK_METHOD1(replayMission,
                 void(int8
                         id));
};


#endif //MARKOS_MAIN_MOCKMISSIONMANAGER_H
