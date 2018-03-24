//
// Created by Oleksandra Baukh on 3/4/18.
//

#ifndef MARKOS_INMEMORYMISSIONMANAGER_H
#define MARKOS_INMEMORYMISSIONMANAGER_H


#include <drivers/MotorDriver.h>
#include <TimerListener.h>
#include <Timer.h>
#include "MissionManager.h"

struct MissionEvent {
    Direction direction;
    Speed speed;
    long duration;
};

class InMemoryMissionManager : public MissionManager, public MotorDriverCommandListener, public TimerListener {

    MotorDriver *motorDriver;
    Timer &timer;
    Clock *clock;
private:

    static const int eventsSize = 10;
    MissionEvent events[eventsSize] = {};
    int recordIndex{0};
    int replayIndex{0};
    long previousTime{0};

    void addMissionEvent(MissionEvent missionEvent);

public:

    InMemoryMissionManager(MotorDriver &motorDriver, Timer &timer, Clock &clock);

    void onEvent(Direction direction, Speed speed) override;

    void onMotorStop() override;

    void onEvent() override;

    void recordMission() override;

    void stopMissionRecording() override;

    void stopMissionReplay() override;

    void recordMission(int8 id) override;

    void replayLastMission() override;

    void replayMission(int8 id) override;


};


#endif //MARKOS_INMEMORYMISSIONMANAGER_H
