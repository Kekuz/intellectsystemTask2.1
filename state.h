#ifndef LAB2_STATE_H
#define LAB2_STATE_H

enum Action
{
    NONE,
    Inc3,
    Mult2,
    Dec2,
    Div2,
    Dec3,
    Inc2,
};


struct State
{
    int data;
    State* par;
    Action act;
    State(int value, State* parent, Action action) {
        data = value;
        par = parent;
        act = action;
    }
};

void PrintPath(State* uZel);

State* Algorithm(int start, int end);

State* AlgorithmReverse(int start, int end);

#endif //LAB2_STATE_H
