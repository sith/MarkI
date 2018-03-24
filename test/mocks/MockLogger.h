//
// Created by Oleksandra Baukh on 3/24/18.
//

#ifndef MARKOS_MAIN_MOCKLOGGER_H
#define MARKOS_MAIN_MOCKLOGGER_H

#include "gmock/gmock.h"
#include <logger/Logger.h>

class MockLogger : public Logger {
public:
    MOCK_METHOD1(logAppend,
            Logger*(const char *c));
    MOCK_METHOD1(logAppend,
            Logger*(int number));
    MOCK_METHOD1(logAppend,
            Logger*(long number));
    MOCK_METHOD0(newLine,
            Logger*());
};

#endif //MARKOS_MAIN_MOCKLOGGER_H
