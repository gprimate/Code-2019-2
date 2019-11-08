#include "planet.h"

Planet::Planet() {
    this->name = "";
    this->visitTime = 0;
}

Planet::Planet(std::string name, int visitTime) {
    this->name = name;
    this->visitTime = visitTime;
}

std::string Planet::getName() {
    return this->name;
}

int Planet::getTime() {
    return this->visitTime;
}
