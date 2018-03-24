//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARKOS_OBSTACLESENSOR_H
#define MARKOS_OBSTACLESENSOR_H


#include <collections/List.h>
#include <collections/LinkedList.h>
#include <CycleListener.h>

class Obstacle {
public:
    bool left;
    bool forward;
    bool right;

    Obstacle(bool left = false, bool forward = false, bool right = false);


    operator bool() const;
};

class ObstacleListener {
public:
    virtual void onEvent(const Obstacle &obstacle) = 0;
};

class ObstacleSensor : public mark_os::cycle::CycleListener {
    Pointer<List<ObstacleListener>> listeners{new LinkedList<ObstacleListener>};
public:
    void addListener(ObstacleListener *obstacleListener);

    void removeListener(ObstacleListener *obstacleListener);

    void onEvent(unsigned long cycleNumber) override;

    virtual Obstacle read() = 0;

};

#endif //MARKOS_OBSTACLESENSOR_H
