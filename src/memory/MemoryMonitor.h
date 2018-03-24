//
// Created by Oleksandra Baukh on 2/25/18.
//

#ifndef MARKOS_MEMORYMONITOR_H
#define MARKOS_MEMORYMONITOR_H

class MemoryMonitor {
public:
    virtual int available()= 0;
};

#endif //MARKOS_MEMORYMONITOR_H
