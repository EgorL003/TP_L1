#pragma once

#include "Submarine.h"
#include "Sail.h"
#include "Boat.h"
#include <fstream>

class Keeper {
    Ship** data;
    int size;
public:
    Keeper();
    ~Keeper();
    int getSize();
    void add();
    void add(int _type, ifstream& fin);
    void edit();
    void del();
    void save();
    void load();
    friend ostream& operator<<(ostream& out, Keeper& obj);
};
