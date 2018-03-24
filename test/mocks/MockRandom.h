//
// Created by Fedorov, Alex on 2/3/18.
//

#ifndef MARKOS_MOCKRANDOM_H
#define MARKOS_MOCKRANDOM_H

#include "gmock/gmock.h"

#include <Random.h>

class MockRandom : public Random {
public:
    MOCK_METHOD0(random,
                 int());

    MOCK_METHOD2(random,
                 int(int
                         start, int
                         end));
};


#endif //MARKOS_MOCKRANDOM_H
