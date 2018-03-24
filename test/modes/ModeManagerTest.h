//
// Created by Fedorov, Alex on 1/28/18.
//

#ifndef MARKOS_MODEMANAGERTEST_H
#define MARKOS_MODEMANAGERTEST_H


#include <gtest/gtest.h>
#include <modes/ModeManager.h>
#include <environment/Environment.h>
#include "../mocks/MockLogger.h"
#include "../mocks/PassThroughLoggerFactory.h"

class ModeManagerTest : public ::testing::Test {
protected:
    ModeManager *modeManager;
    MockLogger mockLogger;
    PassThroughLoggerFactory loggerFactory{mockLogger};

    void SetUp() override {
        LoggerFactory::setLoggerFactory(&loggerFactory);
        modeManager = new ModeManager;
    }

    void TearDown() override {
        delete modeManager;
        modeManager = nullptr;
    }
};


#endif //MARKOS_MODEMANAGERTEST_H
