//
// Created by Oleksandra Baukh on 1/17/18.
//

#ifndef MARK1_MARKIMODELISTENER_H
#define MARK1_MARKIMODELISTENER_H

#include <modes/supervised/SupervisedMode.h>
#include <modes/freerun/FreeRunMode.h>
#include <modes/missionReplay/ReplayMissionMode.h>
#include <logger/LoggerFactory.h>
#include "ModeListener.h"
#include "../logger/Logger.h"

class ModeManager : public ModeListener {
    Mode *currentMode;

    NoopMode noopMode;
    SupervisedMode supervisedMode;
    FreeRunMode freeRunMode;
    ReplayMissionMode replayMissionMode;


    Logger *logger = LoggerFactory::newLogger("ModeManager");
    
    void stopCurrentMode();

public:
    ModeManager();

    virtual ~ModeManager();

    Mode &getCurrentMode() const;

    void onModeChange(ModeName mode) override;

    void initMode(Mode &pMode);
};


#endif //MARK1_MARKIMODELISTENER_H
