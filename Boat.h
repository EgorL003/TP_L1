#pragma once

#include "Ship.h"

class Boat : public Ship {
    int destination;
    string material;
    int speed;
    int people;
    string _class;
public:
    Boat();
    Boat(ifstream& fin);
    ~Boat();
    void edit();
    void save(ofstream& fout);
    void print(ostream& out);
};
