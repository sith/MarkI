//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARKOS_MOCKMOTORDRIVER_H
#define MARKOS_MOCKMOTORDRIVER_H

#include "../../src/drivers/MotorDriver.h"
#include "gmock/gmock.h"

class MockMotorDriver : public MotorDriver {
public:
    MOCK_METHOD2(executeInternal,
                 void(Direction
                         direction, Speed
                         speed));

    MOCK_METHOD0(stopInternal,
                 void());
};


#endif //MARKOS_MOCKMOTORDRIVER_H
