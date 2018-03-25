//
// Created by Oleksandra Baukh on 3/25/18.
//

#ifndef MARKOS_MAIN_REMOTECONTROLLERTEST_H
#define MARKOS_MAIN_REMOTECONTROLLERTEST_H

#include <gtest/gtest.h>
#include <controller/RemoteController.h>


//TODO fix this
#include "../../../controller/test/MockReceiver.h"
#include "../mocks/MockModeListener.h"

class RemoteControllerTest : public testing::Test {
protected:
    Message<mark_os::controller::ControllerState> message;
    MockModeListener mockModeListener;

    mark_os::communication::MockReceiver<mark_os::controller::ControllerState> mockReceiver;
    RemoteController remoteController{mockReceiver};

    void SetUp() override;
};


#endif //MARKOS_MAIN_REMOTECONTROLLERTEST_H
