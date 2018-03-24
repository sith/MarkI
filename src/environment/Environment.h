//
// Created by Oleksandra Baukh on 1/10/18.
//

#ifndef MARKOS_ENVIRONMENT_H
#define MARKOS_ENVIRONMENT_H


#include <modes/ModeManager.h>
#include <sensors/ObstacleSensor.h>
#include <filesystem/FileSystem.h>
#include <memory/MemoryMonitor.h>
#include <Timer.h>
#include <Cycle.h>
#include "../controller/Controller.h"
#include "../logger/LoggerFactory.h"
#include "../Random.h"

class Environment {
    static Environment *environment;
protected:
public:


    static Environment &getEnvironment();

    virtual ModeManager &getModeManager()= 0;

    virtual mark_os::cycle::Cycle &getCycle()= 0;

    void init();

    void loop();

    virtual Timer &getTimer()= 0;

    virtual Controller &getController()  = 0;

    virtual Clock &getClock()  =0;

    virtual MotorDriver &getMotorDriver()  = 0;

    virtual ObstacleSensor &getObstacleSensor()  = 0;

    virtual mark_os::filesystem::FileSystem &getFileSystem()  = 0;

    virtual MemoryMonitor &getMemoryMonitor()  =0;

    virtual MissionManager &getMissionManager()  =0;

    static void setEnvironment(Environment &environment);
};


#endif //MARKOS_ENVIRONMENT_H
