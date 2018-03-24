//
// Created by Fedorov, Alex on 2/28/18.
//

#ifndef MARKOS_MISSIONMANAGER_H
#define MARKOS_MISSIONMANAGER_H


#include <memory/Pointer.h>
#include "../types.h"

class MissionManager {
public:
    virtual void recordMission()= 0;

    virtual void stopMissionRecording()= 0;

    virtual void stopMissionReplay()= 0;

    virtual void recordMission(int8 id)= 0;

    virtual void replayLastMission()= 0;

    virtual void replayMission(int8 id)= 0;
};


#endif //MARKOS_MISSIONMANAGER_H
