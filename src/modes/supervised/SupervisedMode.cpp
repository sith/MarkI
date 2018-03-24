//
// Created by Oleksandra Baukh on 2/4/18.
//

#include <environment/Environment.h>
#include "SupervisedMode.h"

const void SupervisedMode::process() {
    return;
}

void SupervisedMode::stop() {
    Environment::getEnvironment().getMotorDriver().stop();
    Environment::getEnvironment().getController().removeListener(*this);
    Environment::getEnvironment().getObstacleSensor().removeListener(this);
    Environment::getEnvironment().getMissionManager().stopMissionRecording();
}

SupervisedMode::SupervisedMode() : Mode(ModeName::SUPERVISED) {
}

void SupervisedMode::onEvent(Command command) {

    auto motorDriver = &Environment::getEnvironment().getMotorDriver();

    switch (command) {
        case Command::FORWARD:
            motorDriver->execute(Direction::FORWARD, Speed::MEDIUM_SPEED);
            break;
        case Command::LEFT:
            motorDriver->execute(Direction::TURN_LEFT, Speed::LOW_SPEED);
            break;
        case Command::RIGHT:
            motorDriver->execute(Direction::TURN_RIGHT, Speed::LOW_SPEED);
            break;
        case Command::BACKWARD:
            motorDriver->execute(Direction::BACKWARD, Speed::MEDIUM_SPEED);
            break;
        case Command::STOP:
            motorDriver->stop();
            break;
        default:
            break;
    }
}

SupervisedMode::~SupervisedMode() {
}

void SupervisedMode::init() {
    Environment::getEnvironment().getController().addListener(*this);
    Environment::getEnvironment().getObstacleSensor().addListener(this);
    Environment::getEnvironment().getMissionManager().recordMission();
}

void SupervisedMode::onEvent(const Obstacle &obstacle) {
    if (obstacle && Environment::getEnvironment().getMotorDriver().getCurrentDirection() != Direction::BACKWARD) {
        Environment::getEnvironment().getMotorDriver().stop();
    }
}
