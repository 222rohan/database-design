#include "dbdesign.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair< set<string> , set<string> >> fdSet;
    pair< set<string> , set<string> > t[6];
    t[0] = { {"A", "B"}, {"C", "D"} };
    t[1] = { {"A", "F"}, {"D"} };
    t[2] = { {"D", "E"}, {"F"} };
    t[3] = { { "C" }, {"G"} };
    t[4] = { {"F"}, {"E"} };
    t[5] = { {"G"}, {"A"} };

    for(int i = 0; i < 6; i++){
        fdSet.push_back(t[i]);
    }

    set<string> X = {"A", "F"};
    set<string> Aplus = closure(X, fdSet);
    for(auto i : Aplus){
        cout << i << " ";
    }
    return 0;
}