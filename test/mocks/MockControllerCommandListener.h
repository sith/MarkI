//
// Created by Fedorov, Alex on 2/3/18.
//

#ifndef MARKOS_MockControllerCommandListener_H
#define MARKOS_MockControllerCommandListener_H

#include <controller/ControllerCommandListener.h>
#include "gmock/gmock.h"

class MockControllerCommandListener : public ControllerCommandListener {
public:
    MOCK_METHOD1(onEvent,
                 void(Command
                         command));

    virtual ~MockControllerCommandListener() {}
};

#endif //MARKOS_ASDF_H
