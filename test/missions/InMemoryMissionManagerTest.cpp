//
// Created by Oleksandra Baukh on 3/4/18.
//

#include <gmock/gmock.h>
#include "InMemoryMissionManagerTest.h"


using ::testing::Mock;
using ::testing::Return;
using ::testing::Exactly;
using ::testing::AnyNumber;


void InMemoryMissionManagerTest::SetUp() {
    Mock::VerifyAndClearExpectations(&clock);
    Mock::VerifyAndClearExpectations(&motorDriver);
}

TEST_F(InMemoryMissionManagerTest, replayRecord) {
    EXPECT_CALL(clock, getTime()).Times(Exactly(4));
    EXPECT_CALL(motorDriver, execute(Direction::FORWARD, Speed::LOW_SPEED)).Times(Exactly(2));
    EXPECT_CALL(motorDriver, execute(Direction::BACKWARD, Speed::HIGH_SPEED)).Times(Exactly(2));
    EXPECT_CALL(motorDriver, stop()).Times(Exactly(2));

    missionManager.recordMission();

    missionManager.onEvent(Direction::FORWARD, Speed::LOW_SPEED);
    missionManager.onEvent(Direction::BACKWARD, Speed::HIGH_SPEED);
    missionManager.onMotorStop();

    missionManager.stopMissionRecording();

     missionManager.replayLastMission();

     missionManager.onEvent();
     missionManager.onEvent();
     missionManager.onEvent();
}


TEST(InMemoryMissionManagerTest, stopReplaying) {


}
