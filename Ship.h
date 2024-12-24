#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Ship {
    int type;
    bool error;
public:
    void setType(int _type);
    int getType();
    bool isError();
    void setError(bool _error);
    virtual void save(ofstream& fout) = 0;
    virtual void edit() = 0;
    virtual void print(ostream& out) = 0;

    virtual ~Ship() = 0;
};
