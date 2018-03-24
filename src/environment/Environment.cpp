//
// Created by Oleksandra Baukh on 1/10/18.
//

#include "Environment.h"

Environment *Environment::environment;

void Environment::loop() {
    getCycle().next();
    getModeManager().getCurrentMode().process();
}

void Environment::init() {
    auto pController = &getController();
    getCycle().getListeners()->add(pController);
    getCycle().getListeners()->add(&getTimer());
    getCycle().getListeners()->add(&getObstacleSensor());

    getController().addModeListener(getModeManager());
}


Environment &Environment::getEnvironment() {
    return *environment;
}

void Environment::setEnvironment(Environment &environment) {
    Environment::environment = &environment;
}
