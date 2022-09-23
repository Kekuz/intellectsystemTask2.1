#include <iostream>
#include <set>
#include <vector>
#include "state.h"
#include <algorithm>

using namespace std;

state find_leaf(int a, int b){
    vector <state> leafs = {state(a)};
    set<int> seen;

    while (true){
        vector <state> new_leafs = {};


        for(auto i : leafs)
        {
            auto cur_value = i.value * 2;
            if (seen.find(cur_value) == seen.end() && cur_value <= b){
                new_leafs.push_back(state(cur_value, "*2", &i));
                seen.insert(cur_value);
            }
            if (cur_value == b){
                cout<<"Visited nodes count: "<< seen.size()<<endl;
                return new_leafs.back();
            }

            cur_value = i.value + 3;
            if (seen.find(cur_value) == seen.end()){
                new_leafs.push_back(state(cur_value, "+3", &i));
                seen.insert((cur_value));
            }
            if (cur_value == b){
                cout<<"Visited nodes count: "<< seen.size()<<endl;
                return new_leafs.back();
            }
        }
        leafs = new_leafs;
    }
}

vector<state> find_seq(state leaf){
    vector <state> seq = {leaf};
    auto cur = &leaf;
    while (true){
        state* parent = cur->parent;
        if (parent == nullptr){
            reverse(seq.begin(), seq.end());
            return seq;
        }
        seq.push_back(*parent);
        cur = parent;
    }
}


int main() {
    int a = 2;
    int b = 100;
    cout << "Imput a: " << endl;
    //cin >> a;
    cout << "Imput b: " << endl;
    //cin >> b;

    auto leaf = find_leaf(a,b);
    auto op_seq = find_seq(leaf);

    for (auto x: op_seq){
        cout << x.value << endl;
    }
    cout << op_seq.size() << endl;

}
