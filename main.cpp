#include <iostream>
#include <ctime>
#include "State.h"

using namespace std;

int main()
{
    int start = 2;
    int finish = 100;
    int taskNum;

    cout << "1. Прямой поиск\n2. Обратный поиск" << endl;
    cin >> taskNum;
    cout << "Введите начальное и конечное число: " << endl;
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