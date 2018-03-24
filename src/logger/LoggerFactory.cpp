//
// Created by Fedorov, Alex on 2/3/18.
//

#include "LoggerFactory.h"

LoggerFactory *LoggerFactory::loggerFactory;

void LoggerFactory::setLoggerFactory(LoggerFactory *loggerFactory) {
    LoggerFactory::loggerFactory = loggerFactory;
}

Logger *LoggerFactory::newLogger(const char *name) {
    return loggerFactory->createLogger(name);
}
