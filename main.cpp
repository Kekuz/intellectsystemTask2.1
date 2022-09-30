#include <iostream>
#include <ctime>
#include "State.h"

using namespace std;

int main()
{
    int start;
    int finish;
    int taskNum;

    cout << "1. Direct search\n2. Reverse search" << endl;
    cin >> taskNum;
    cout << "Enter the start and end number: " << endl;
    cin >> start >> finish;

    clock_t s, f;
    State* test;

    s = clock(); // Метка начала
    if (taskNum == 1){
        test = Algorithm(start, finish);
    }
    else if (taskNum == 2){
        test = AlgorithmReverse(finish, start);
    }
    else return 0;
    f = clock(); // Метка конца
    cout << ((f - s) / CLOCKS_PER_SEC) << " sec. " << endl;
    PrintPath(test);
}