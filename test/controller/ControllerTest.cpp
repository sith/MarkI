//
// Created by Fedorov, Alex on 2/3/18.
//

#include "ControllerTest.h"
#include "../mocks/MockModeListener.h"
#include "../mocks/MockControllerCommandListener.h"

using ::testing::Exactly;
using ::testing::_;

void ControllerTest::SetUp() {
    testController = new TestController();
    mockModeListener = new MockModeListener;

    controllerCommandListener1 = new MockControllerCommandListener;
    controllerCommandListener2 = new MockControllerCommandListener;

    testController->addModeListener(*mockModeListener);
    testController->addListener(*controllerCommandListener1);
    testController->addListener(*controllerCommandListener2);
}

void ControllerTest::TearDown() {
    delete testController;
    delete mockModeListener;
    delete controllerCommandListener1;
    delete controllerCommandListener2;
}

void ControllerTest::changeMode(ModeName expectedModeName) {
    testController->setCommand(Command::SELECT_MODE);
    testController->setModeName(expectedModeName);
}

TEST_F(ControllerTest, selectMode) {
    ModeName expectedModeName = ModeName::FIXED_ROUTE;
    EXPECT_CALL(*controllerCommandListener1, onEvent(_)).Times(Exactly(0));
    EXPECT_CALL(*controllerCommandListener2, onEvent(_)).Times(Exactly(0));

    EXPECT_CALL(*mockModeListener, onModeChange(expectedModeName)).Times(Exactly(1));
    changeMode(expectedModeName);
    testController->onEvent(0);

    EXPECT_CALL(*mockModeListener, onModeChange(ModeName::NONE)).Times(Exactly(2));
    changeMode(ModeName::NONE);
    testController->onEvent(1);

    testController->setCommand(Command::STOP_MODE);
    testController->onEvent(2);
    testController->onEvent(3);
}

TEST_F(ControllerTest, selectControls) {

    EXPECT_CALL(*controllerCommandListener1, onEvent(Command::FORWARD)).Times(Exactly(1));
    EXPECT_CALL(*controllerCommandListener1, onEvent(Command::BACKWARD)).Times(Exactly(1));
    EXPECT_CALL(*controllerCommandListener1, onEvent(Command::LEFT)).Times(Exactly(1));
    EXPECT_CALL(*controllerCommandListener1, onEvent(Command::RIGHT)).Times(Exactly(1));
    EXPECT_CALL(*controllerCommandListener1, onEvent(Command::STOP)).Times(Exactly(1));

    EXPECT_CALL(*controllerCommandListener2, onEvent(Command::FORWARD)).Times(Exactly(1));
    EXPECT_CALL(*controllerCommandListener2, onEvent(Command::BACKWARD)).Times(Exactly(1));
    EXPECT_CALL(*controllerCommandListener2, onEvent(Command::LEFT)).Times(Exactly(1));
    EXPECT_CALL(*controllerCommandListener2, onEvent(Command::RIGHT)).Times(Exactly(0));
    EXPECT_CALL(*controllerCommandListener2, onEvent(Command::STOP)).Times(Exactly(0));

    testController->setCommand(Command::FORWARD);
    testController->onEvent(0);

    testController->setCommand(Command::BACKWARD);
    testController->onEvent(1);

    testController->setCommand(Command::LEFT);
    testController->onEvent(2);

    testController->removeListener(*controllerCommandListener2);

    testController->setCommand(Command::RIGHT);
    testController->onEvent(3);

    testController->setCommand(Command::STOP);
    testController->onEvent(4);

    testController->onEvent(5);

}
