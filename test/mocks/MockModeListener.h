//
// Created by Fedorov, Alex on 2/3/18.
//

#ifndef MARKOS_MOCKMODELISTENER_H
#define MARKOS_MOCKMODELISTENER_H

#include <modes/ModeListener.h>
#include "gmock/gmock.h"

class MockModeListener : public ModeListener {
public:
    virtual ~MockModeListener() {}

    MOCK_METHOD1(onModeChange,
                 void(ModeName
                         mode));
};

#endif //MARKOS_MOCKMODELISTENER_H
