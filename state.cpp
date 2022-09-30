#include <iostream>
#include<unordered_set>
#include <queue>
#include <vector>
#include "State.h"
using namespace std;

void PrintPath(State* uZel) {
    int count = 0;
    while (uZel != nullptr) {
        cout << uZel->data << " -> ";
        uZel = uZel->par;
        count++;
    }
    cout << "\nКоличество операций: " << count-1 << endl;
}


// Прямой поиск
State* Algorithm(int start, int end) {
    State* head = new State(start, nullptr, NONE); //  начальная вершинa
    unordered_set<int> set; // хранит все пройденные числа
    queue<State*> q; // очередь для обхода в ширину
    q.push(head);
    while (!q.empty()) {
        State* cur = q.front();
        q.pop();
        if (cur->data == end)
            return cur;
        State* left = new State(cur->data * 2, cur, Mult2); // * 2
        State* right = new State(cur->data + 3, cur, Inc3); // + 3
        if (set.find(left->data) == set.end()) q.push(left);
        if (set.find(right->data) == set.end()) q.push(right);

        set.insert(left->data);
        set.insert(right->data);
    }
    return nullptr;
}

// Обратный поиск
State* AlgorithmReverse(int start, int end) {
    State* head = new State(start, nullptr, NONE); //  начальная вершинa
    unordered_set<int> set; // хранит все пройденные числа
    queue<State*> q; // очередь для обхода в ширину
    q.push(head);
    while (!q.empty()) {
        State* cur = q.front();
        q.pop();
        if (cur->data == end)
            return cur;
        int curData = cur->data;

        if (curData % 2 == 0) {
            State* left = new State(cur->data / 2, cur, Div2); // / 2
            if (set.find(left->data) == set.end()) q.push(left);
            set.insert(left->data);
        }

        State* right = new State(cur->data - 3, cur, Dec3); // - 3
        if (set.find(right->data) == set.end()) q.push(right);
        set.insert(right->data);
    }
    return nullptr;
}