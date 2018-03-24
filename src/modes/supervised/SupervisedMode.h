//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARKOS_SUPERVISEDMODE_H
#define MARKOS_SUPERVISEDMODE_H


#include <modes/Mode.h>
#include <drivers/MotorDriver.h>
#include <controller/ControllerCommandListener.h>
#include <sensors/ObstacleSensor.h>

class SupervisedMode : public Mode, public ControllerCommandListener, public ObstacleListener {
public:

    SupervisedMode();

    const void process() override;

    void stop() override;

    void init() override;

    void onEvent(Command command) override;

    void onEvent(const Obstacle &obstacle) override;

    ~SupervisedMode() override;
};


#endif //MARKOS_SUPERVISEDMODE_H
