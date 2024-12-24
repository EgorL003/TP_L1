#pragma once

#include "Ship.h"

class Sail : public Ship {
    string name;
    string typeSail;
    int destination;
    int _long;
    int speed;
    int people;
public:
    Sail();
    Sail(ifstream& fin);
    ~Sail();
    void edit();
    void save(ofstream& fout);
    void print(ostream& out);
};
