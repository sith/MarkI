//
// Created by Oleksandra Baukh on 3/25/18.
//

#ifndef MARKOS_MAIN_REMOTECONTROLLER_H
#define MARKOS_MAIN_REMOTECONTROLLER_H


#include <ControllerStateReceiver.h>

#include "Controller.h"

class RemoteController : public Controller {
    static const int positiveThreshold = 100;
    static const int negativeThreshold = -100;
    mark_os::controller::ControllerStateReceiver controllerReceiver;
public:
    RemoteController(mark_os::communication::Receiver<mark_os::controller::ControllerState> &receiver);

    Command readControllerCommand() override;
};

#endif //MARKOS_MAIN_REMOTECONTROLLER_H
