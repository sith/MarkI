//
// Created by Fedorov, Alex on 2/3/18.
//

#ifndef MARKOS_ControllerCommandListener_H
#define MARKOS_ControllerCommandListener_H

#include "Command.h"

class ControllerCommandListener {
public:
    virtual void onEvent(Command command)= 0;
};

#endif //MARKOS_ASDF_H
