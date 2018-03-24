//
// Created by Oleksandra Baukh on 1/19/18.
//

#ifndef MARK1_LOGGERFACTORY_H
#define MARK1_LOGGERFACTORY_H

#include "Logger.h"

class LoggerFactory {
    static LoggerFactory *loggerFactory;
public:

    static Logger *newLogger(const char *name);

    static void setLoggerFactory(LoggerFactory *loggerFactory);

    virtual Logger *createLogger(const char *name)= 0;
};

#endif //MARK1_LOGGERFACTORY_H
