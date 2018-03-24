//
// Created by Oleksandra Baukh on 2/25/18.
//

#ifndef MARKOS_MOCKENVIRONMENT_H
#define MARKOS_MOCKENVIRONMENT_H

#include "gmock/gmock.h"
#include <environment/Environment.h>
using namespace mark_os::filesystem;
class MockEnvironment : public Environment {
public:
    MOCK_METHOD0(getModeManager,
                 ModeManager&());
    MOCK_METHOD0(getCycle,
                 mark_os::cycle::Cycle&());
    MOCK_METHOD0(getTimer,
                 Timer&());
    MOCK_METHOD0(getController,
                 Controller&());
    MOCK_METHOD0(getClock,
                 Clock&());
    MOCK_METHOD0(getMotorDriver,
                 MotorDriver&());
    MOCK_METHOD0(getObstacleSensor,
                 ObstacleSensor&());
    MOCK_METHOD0(getFileSystem,
                 FileSystem&());
    MOCK_METHOD0(getMemoryMonitor,
                 MemoryMonitor&());
    MOCK_METHOD0(getMissionManager,
                 MissionManager&());
};



#endif //MARKOS_MOCKENVIRONMENT_H
