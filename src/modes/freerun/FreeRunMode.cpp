//
// Created by Oleksandra Baukh on 2/17/18.
//

#include <environment/Environment.h>
#include "FreeRunMode.h"

FreeRunMode::FreeRunMode() : Mode(ModeName::FREE_RUN) {}

FreeRunMode::~FreeRunMode() {}

const void FreeRunMode::process() {
}

void FreeRunMode::init() {
    Environment::getEnvironment().getObstacleSensor().addListener(this);
    Environment::getEnvironment().getMotorDriver().execute(Direction::FORWARD, Speed::MEDIUM_SPEED);
    Environment::getEnvironment().getMissionManager().recordMission();
}

void FreeRunMode::stop() {
    Environment::getEnvironment().getMotorDriver().stop();
    Environment::getEnvironment().getObstacleSensor().removeListener(this);
    Environment::getEnvironment().getMissionManager().stopMissionRecording();
}

void FreeRunMode::onEvent(const Obstacle &obstacle) {
    if (obstacle.left) {
        Environment::getEnvironment().getMotorDriver().execute(Direction::TURN_RIGHT, Speed::LOW_SPEED);
    } else if (obstacle.right) {
        Environment::getEnvironment().getMotorDriver().execute(Direction::TURN_LEFT, Speed::LOW_SPEED);
    } else if (obstacle.forward) {
        Environment::getEnvironment().getMotorDriver().execute(Direction::TURN_RIGHT, Speed::LOW_SPEED);
    } else {
        Environment::getEnvironment().getMotorDriver().execute(Direction::FORWARD, Speed::MEDIUM_SPEED);
    }
}
