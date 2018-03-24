//
// Created by Oleksandra Baukh on 3/24/18.
//

#ifndef MARKOS_MAIN_PASSTHROUGHLOGGERFACTORY_H
#define MARKOS_MAIN_PASSTHROUGHLOGGERFACTORY_H

#include "../../src/logger/LoggerFactory.h"

class PassThroughLoggerFactory : public LoggerFactory {
    Logger *logger;
public:
    PassThroughLoggerFactory(Logger &logger) : logger(&logger) {}

    Logger *createLogger(const char *name) override {
        return logger;
    }
};

#endif //MARKOS_MAIN_PASSTHROUGHLOGGERFACTORY_H
