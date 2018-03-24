//
// Created by Oleksandra Baukh on 1/20/18.
//

#include "NoopState.h"
void NoopState::stop() {

}

State *NoopState::execute() {
    return this;
}
