//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARKOS_SUPERVISEDMODETEST_H
#define MARKOS_SUPERVISEDMODETEST_H


#include <gtest/gtest.h>
#include <modes/supervised/SupervisedMode.h>
#include "../../mocks/MockMotorDriver.h"
#include "../../mocks/MockController.h"
#include "../../mocks/MockObstacleSensor.h"
#include "../../mocks/MockEnvironment.h"

class SupervisedModeTest : public testing::Test {

protected:
    MockEnvironment environment;

    void SetUp() override;

    void TearDown() override;

    SupervisedMode supervisedMode;
    MockMotorDriver mockMotorDriver;
    MockController mockController;
    MockObstacleSensor obstacleSensor;
};


#endif //MARKOS_SUPERVISEDMODETEST_H
