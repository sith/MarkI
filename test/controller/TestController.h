//
// Created by Fedorov, Alex on 2/3/18.
//

#ifndef MARKOS_TESTCONTROLLER_H
#define MARKOS_TESTCONTROLLER_H


#include <controller/Controller.h>

class TestController : public Controller {

    Command command;

public:

    Command readControllerCommand() override;

    void setCommand(Command command);

    void setModeName(ModeName modeName);

};


#endif //MARKOS_TESTCONTROLLER_H
