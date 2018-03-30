//
// Created by Oleksandra Baukh on 3/25/18.
//

#include "RemoteControllerTest.h"

using ::testing::Mock;
using ::testing::Exactly;
using ::testing::Return;

void RemoteControllerTest::SetUp() {
    message = {};
    Mock::VerifyAndClearExpectations(&mockReceiver);
    Mock::VerifyAndClearExpectations(&mockModeListener);

    remoteController.addModeListener(mockModeListener);

}


TEST_F(RemoteControllerTest, forwardCommand) {
    message.content.leftY = 100;
    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(1)).WillOnce(Return(mark_os::commons::optional(message)));
    ASSERT_EQ(remoteController.readControllerCommand(), Command::FORWARD);
}

TEST_F(RemoteControllerTest, backwardCommand) {
    message.content.leftY = -100;
    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(1)).WillOnce(Return(mark_os::commons::optional(message)));
    ASSERT_EQ(remoteController.readControllerCommand(), Command::BACKWARD);
}

TEST_F(RemoteControllerTest, turnLeftCommand) {
    message.content.leftX = -100;
    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(1)).WillOnce(Return(mark_os::commons::optional(message)));
    ASSERT_EQ(remoteController.readControllerCommand(), Command::LEFT);
}

TEST_F(RemoteControllerTest, turnRightCommand) {
    message.content.leftX = 100;
    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(1)).WillOnce(Return(mark_os::commons::optional(message)));
    ASSERT_EQ(remoteController.readControllerCommand(), Command::RIGHT);
}

TEST_F(RemoteControllerTest, stopCommand) {
    message.content.leftX = 0;
    message.content.leftY = 0;
    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(1)).WillOnce(Return(mark_os::commons::optional(message)));
    ASSERT_EQ(remoteController.readControllerCommand(), Command::STOP);
}

TEST_F(RemoteControllerTest, testSensetivity) {
    message.content.leftX = 99;
    message.content.leftY = 99;
    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(1)).WillOnce(Return(mark_os::commons::optional(message)));
    ASSERT_EQ(remoteController.readControllerCommand(), Command::STOP);
}

TEST_F(RemoteControllerTest, stopMode) {
    message.content.left = true;
    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(1)).WillOnce(Return(mark_os::commons::optional(message)));
    ASSERT_EQ(remoteController.readControllerCommand(), Command::STOP_MODE);
}

TEST_F(RemoteControllerTest, supervisedMode) {
    message.content.a = true;
    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(2)).WillRepeatedly(Return(mark_os::commons::optional(message)));
    EXPECT_CALL(mockModeListener, onModeChange(ModeName::SUPERVISED)).Times(Exactly(1));
    remoteController.onEvent(1);
    ASSERT_EQ(remoteController.readControllerCommand(), Command::SELECT_MODE);
}

TEST_F(RemoteControllerTest, freeRunMode) {
    message.content.b = true;
    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(2)).WillRepeatedly(Return(mark_os::commons::optional(message)));
    EXPECT_CALL(mockModeListener, onModeChange(ModeName::FREE_RUN)).Times(Exactly(1));
    remoteController.onEvent(1);
    ASSERT_EQ(remoteController.readControllerCommand(), Command::SELECT_MODE);
}

TEST_F(RemoteControllerTest, missionReplayMode) {
    message.content.x = true;
    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(2)).WillRepeatedly(Return(mark_os::commons::optional(message)));
    EXPECT_CALL(mockModeListener, onModeChange(ModeName::MISSION_REPLAY)).Times(Exactly(1));
    remoteController.onEvent(1);
    ASSERT_EQ(remoteController.readControllerCommand(), Command::SELECT_MODE);
}



