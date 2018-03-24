//
// Created by Oleksandra Baukh on 1/19/18.
//

#include "ModeName.h"
#include "Mode.h"


Mode::Mode(ModeName modeName) : modeName(modeName) {}

ModeName &Mode::getModeName() {
    return modeName;
}

char Mode::getModeNameString() {
    return getModeNameId(modeName);
}

char Mode::getModeNameId(ModeName &modeName) {
    switch (modeName) {
        case ModeName::NONE:
            return '0';
        case ModeName::CALIBRATION:
            return '1';
        case ModeName::FREE_RUN:
            return '2';
        case ModeName::SUPERVISED:
            return '3';
        case ModeName::FIXED_ROUTE:
            return '3';
        case ModeName::EXPLORER:
            return '5';
        default:
            return '6';
    }
}

Mode::~Mode() {

}
