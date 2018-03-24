#include "ModeManager.h"
#include "ModeName.h"
#include "../environment/Environment.h"

void ModeManager::onModeChange(ModeName mode) {
    if (currentMode->getModeName() == mode) {
        return;
    }
    stopCurrentMode();
    logger->newLine()->logAppend("New mode");
    switch (mode) {
        case ModeName::CALIBRATION:
            break;
        case ModeName::FREE_RUN:
            initMode(freeRunMode);
            break;
        case ModeName::SUPERVISED:
            initMode(supervisedMode);
            break;
        case ModeName::FIXED_ROUTE:
            break;
        case ModeName::EXPLORER:
            break;
        case ModeName::MISSION_REPLAY:
            initMode(replayMissionMode);
            break;
        case ModeName::NONE:
            initMode(noopMode);
            break;
        default:
            return;
    }
}

void ModeManager::stopCurrentMode() {
    currentMode->stop();
    currentMode = &noopMode;
}

ModeManager::ModeManager() {
    currentMode = &noopMode;
}

Mode &ModeManager::getCurrentMode() const {
    return *currentMode;
}


void ModeManager::initMode(Mode &newMode) {
    currentMode = &newMode;
    currentMode->init();
}

ModeManager::~ModeManager() {}
