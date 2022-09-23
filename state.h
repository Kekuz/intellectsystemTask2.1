#ifndef UNTITLED_STATE_H
#define UNTITLED_STATE_H
#include <iostream>
using namespace std;

class state{
public:
    int value;
    string operation;
    state* parent;
    state(int value, string operation = "", state* parent = nullptr)
    {
        this-> value = value;
        this-> operation = operation;
        this-> parent = parent;
    }
};


#endif //UNTITLED_STATE_H
