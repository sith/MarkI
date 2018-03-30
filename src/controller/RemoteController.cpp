//
// Created by Oleksandra Baukh on 3/25/18.
//

#include "RemoteController.h"


Command RemoteController::readControllerCommand() {

    auto state = controllerReceiver.readControllerState();

    if (!state) {
        return Command::NONE;
    }


    if (state().left) {
        return Command::STOP_MODE;
    }

    if (state().a) {
        modeName = ModeName::SUPERVISED;
        return Command::SELECT_MODE;
    }
    if (state().b) {
        modeName = ModeName::FREE_RUN;
        return Command::SELECT_MODE;
    }
    if (state().x) {
        modeName = ModeName::MISSION_REPLAY;
        return Command::SELECT_MODE;
    }

    if (state().leftX >= positiveThreshold) {
        return Command::RIGHT;
    }

    if (state().leftX <= negativeThreshold) {
        return Command::LEFT;
    }

    if (state().leftY >= positiveThreshold) {
        return Command::FORWARD;
    }

    if (state().leftY <= negativeThreshold) {
        return Command::BACKWARD;
    }
    return Command::STOP;
}

RemoteController::RemoteController(mark_os::communication::Receiver<mark_os::controller::ControllerState> &receiver)
        : controllerReceiver{receiver} {

}
