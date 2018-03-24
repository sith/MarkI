
#include "ObstacleSensor.h"


void ObstacleSensor::addListener(ObstacleListener *obstacleListener) {
    listeners.get()->add(obstacleListener);
}

void ObstacleSensor::removeListener(ObstacleListener *obstacleListener) {
    listeners.get()->removeByPointer(obstacleListener);
}

void ObstacleSensor::onEvent(unsigned long cycleNumber) {
    auto obstacle = read();
    auto iteratorPointer = listeners.get()->iterator();
    auto pIterator = iteratorPointer.get();
    while (pIterator->hasNext()) {
        pIterator->next()->onEvent(obstacle);
    }
}


Obstacle::Obstacle(bool left, bool forward, bool right) : left(left), forward(forward), right(right) {}

Obstacle::operator bool() const {
    return left || forward || right;
}
