//
// Created by Fedorov, Alex on 2/3/18.
//

#ifndef MARKOS_CONTROLLERTEST_H
#define MARKOS_CONTROLLERTEST_H


#include <gtest/gtest.h>
#include "TestController.h"
#include "../mocks/MockModeListener.h"
#include "../mocks/MockControllerCommandListener.h"

class ControllerTest : public ::testing::Test {
protected:
    TestController *testController;
    MockModeListener *mockModeListener;
    MockControllerCommandListener *controllerCommandListener1;
    MockControllerCommandListener *controllerCommandListener2;

    void SetUp() override;

    void TearDown() override;

    void changeMode(ModeName expectedModeName);
};


#endif //MARKOS_CONTROLLERTEST_H
