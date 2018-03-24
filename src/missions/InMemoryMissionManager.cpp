//
// Created by Oleksandra Baukh on 3/4/18.
//

#include "InMemoryMissionManager.h"

void InMemoryMissionManager::recordMission() {
    recordMission(1);
}

void InMemoryMissionManager::stopMissionRecording() {
    motorDriver->removeListener(this);

    auto newTime = clock->getTime();
    addMissionEvent({Direction::NONE, Speed::NONE, newTime - previousTime});
    previousTime = newTime;
}

void InMemoryMissionManager::stopMissionReplay() {
    timer.removeTasksForListener(*this);
    motorDriver->stop();
}

void InMemoryMissionManager::recordMission(int8 id) {
    previousTime = clock->getTime();
    motorDriver->addListener(this);
    recordIndex = 0;
}

void InMemoryMissionManager::replayLastMission() {
    replayMission(1);
}

void InMemoryMissionManager::replayMission(int8 id) {
    replayIndex = 0;

    if (replayIndex <= recordIndex) {
        timer.addTimer(events[replayIndex].duration, *this);
    }
}

void InMemoryMissionManager::addMissionEvent(MissionEvent missionEvent) {
    if (recordIndex < eventsSize) {
        events[recordIndex] = missionEvent;
        recordIndex++;
    }
}

void InMemoryMissionManager::onEvent(Direction direction, Speed speed) {
    auto newTime = clock->getTime();
    addMissionEvent({direction, speed, newTime - previousTime});
    previousTime = newTime;
}

void InMemoryMissionManager::onMotorStop() {
    auto newTime = clock->getTime();
    addMissionEvent({Direction::NONE, Speed::NONE, newTime - previousTime});
    previousTime = newTime;
}

void InMemoryMissionManager::onEvent() {
    if (replayIndex <= recordIndex) {
        MissionEvent missionEvent = events[replayIndex];
        motorDriver->execute(missionEvent.direction, missionEvent.speed);
        ++replayIndex;
        timer.addTimer(missionEvent.duration, *this);
    }
}

InMemoryMissionManager::InMemoryMissionManager(MotorDriver &motorDriver, Timer &timer, Clock &clock) :
        motorDriver(&motorDriver),
        timer(timer),
        clock(&clock) {}
