#ifndef LAB2_STATE_H
#define LAB2_STATE_H

enum Action
{
    NONE,// Для корня
    Inc3,
    Mult2,
    Dec2,
    Div2,//Для обратного алгоритма
    Dec3,//Для обратного алгоритма
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

void PrintPath(State* elem);

State* Algorithm(int start, int end);

State* AlgorithmReverse(int start, int end);

#endif //LAB2_STATE_H
