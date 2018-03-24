//
// Created by Oleksandra Baukh on 2/28/18.
//

#include <environment/Environment.h>
#include "ReplayMissionMode.h"

ReplayMissionMode::ReplayMissionMode() : Mode(ModeName::MISSION_REPLAY) {}

ReplayMissionMode::~ReplayMissionMode() {

}

const void ReplayMissionMode::process() {
    return;
}

void ReplayMissionMode::init() {
    Environment::getEnvironment().getMissionManager().replayLastMission();
}

void ReplayMissionMode::stop() {
    Environment::getEnvironment().getMissionManager().stopMissionReplay();
}
