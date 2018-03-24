//
// Created by Oleksandra Baukh on 2/23/18.
//

#ifndef MARKOS_MOCKOBSTACLESENSOR_H
#define MARKOS_MOCKOBSTACLESENSOR_H

#include <sensors/ObstacleSensor.h>
#include "gmock/gmock.h"

class MockObstacleSensor : public ObstacleSensor {
public:
    MOCK_METHOD1(onEvent,
                 void(unsigned long
                         cycleNumber));

    MOCK_METHOD0(read,
                 Obstacle());
};

#endif //MARKOS_MOCKOBSTACLESENSOR_H
