//
// Created by Fedorov, Alex on 2/28/18.
//

#include "RandomMissionIdGenerator.h"

uint8 RandomMissionIdGenerator::nextId() {
    return random.randomUINT8();
}

RandomMissionIdGenerator::RandomMissionIdGenerator(Random &random) : random(random) {}
