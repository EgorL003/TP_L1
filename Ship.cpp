#include "Ship.h"

void Ship::setType(int _type) {
    type = _type;
}

int Ship::getType() {
    return type;
}

bool Ship::isError() {
    return this->error;
}

void Ship::setError(bool _error) {
    this->error = _error;
}

Ship::~Ship() {
}