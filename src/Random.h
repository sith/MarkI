//
// Created by Oleksandra Baukh on 1/19/18.
//

#ifndef MARK1_RANDOM_H
#define MARK1_RANDOM_H


#include <types.h>

class Random {
public:
    virtual int random()= 0;

    virtual int random(int start, int end)= 0;

    virtual uint8 randomUINT8()= 0;
};


#endif //MARK1_RANDOM_H
