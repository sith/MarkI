//
// Created by Oleksandra Baukh on 1/22/18.
//

#ifndef MARKOS_MOCKCLOCK_H
#define MARKOS_MOCKCLOCK_H

#include <Clock.h>
#include "gmock/gmock.h"

class MockClock : public Clock {
public:
    MOCK_METHOD0(getTime,
                 long());
};

#endif //MARKOS_MOCKCLOCK_H
