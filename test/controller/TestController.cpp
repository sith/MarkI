//
// Created by Fedorov, Alex on 2/3/18.
//

#include "TestController.h"

Command TestController::readControllerCommand() {
    Command tmp = command;
    command = Command::NONE;
    return tmp;
}

void TestController::setCommand(Command command) {
    TestController::command = command;
}

void TestController::setModeName(ModeName modeName) {
    Controller::modeName = modeName;
}
