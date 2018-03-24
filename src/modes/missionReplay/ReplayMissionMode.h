//
// Created by Oleksandra Baukh on 2/28/18.
//

#ifndef MARKOS_REPLAYMISSIONMODE_H
#define MARKOS_REPLAYMISSIONMODE_H


#include <modes/Mode.h>

class ReplayMissionMode : public Mode {
public:
    ReplayMissionMode();

    ~ReplayMissionMode() override;

    const void process() override;

    void init() override;

    void stop() override;
};


#endif //MARKOS_REPLAYMISSIONMODE_H
