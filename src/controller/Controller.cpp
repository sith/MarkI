//
// Created by Oleksandra Baukh on 1/17/18.
//


#include <logger/LoggerFactory.h>
#include "Controller.h"
#include "../modes/ModeListener.h"

void Controller::addModeListener(ModeListener &ml) {
    modeListener = &ml;
}

void Controller::onEvent(unsigned long cycleNumber) {
    Command command = readControllerCommand();
    switch (command) {
        case Command::NONE:
            break;
        case Command::FORWARD:
            notifyOnCommand(Command::FORWARD);
            break;
        case Command::LEFT:
            notifyOnCommand(Command::LEFT);
            break;
        case Command::RIGHT:
            notifyOnCommand(Command::RIGHT);
            break;
        case Command::BACKWARD:
            notifyOnCommand(Command::BACKWARD);
            break;
        case Command::STOP:
            notifyOnCommand(Command::STOP);
            break;
        case Command::STOP_MODE:
            modeListener->onModeChange(ModeName::NONE);
            break;
        case Command::SELECT_MODE:
            modeListener->onModeChange(getModeName());
            break;
    }
}

ModeName Controller::getModeName() const {
    return modeName;
}

Controller::Controller() {}

// TODO unify listeners
void Controller::addListener(ControllerCommandListener &controllerCommandListener) {
    commandListeners.get()->add(&controllerCommandListener);
}

void Controller::removeListener(ControllerCommandListener &controllerCommandListener) {
    commandListeners.get()->removeByPointer(&controllerCommandListener);
}

void Controller::notifyOnCommand(Command command) {
    auto iteratorPointer = commandListeners.get()->iterator();
    while (iteratorPointer.get()->hasNext()) {
        iteratorPointer.get()->next()->onEvent(command);
    }
}

mark_os::commons::List<ControllerCommandListener> *Controller::getCommandListeners() const {
    return commandListeners.get();
}

Controller::~Controller() {}
