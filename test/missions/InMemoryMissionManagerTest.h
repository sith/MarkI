//
// Created by Oleksandra Baukh on 3/4/18.
//

#ifndef MARKOS_INMEMORYMISSIONMANAGERTEST_H
#define MARKOS_INMEMORYMISSIONMANAGERTEST_H


#include <gtest/gtest.h>
#include <missions/InMemoryMissionManager.h>
#include "../mocks/MockClock.h"
#include "../mocks/MockMotorDriver.h"

class InMemoryMissionManagerTest : public ::testing::Test {
protected:
    void SetUp() override;

    MockMotorDriver motorDriver;
    MockClock clock;
    Timer timer{&clock};
    InMemoryMissionManager missionManager{motorDriver, timer, clock};
};


#endif //MARKOS_INMEMORYMISSIONMANAGERTEST_H
