#include "dbdesign.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair< set<string> , set<string> >> fdSet;
    pair< set<string> , set<string> > t[6];
    t[0] = {{"D"}, {"E"}};
    t[1] = {{"A", "B"}, {"E"}};
    t[2] = {{"E"}, {"C"}};
    t[3] = {{"A","B"}, {"C"}};

    for(int i = 0; i < 4; i++){
        fdSet.push_back(t[i]);
    }
    cout << endl;

    vector<pair< set<string> , set<string> >> G = minimalCover(fdSet);
   //print minimal cover
    for(auto fd : G){
        for(auto l : fd.first){
            cout << l << " ";
        }
        cout << "-> ";
        for(auto r : fd.second){
            cout << r << " ";
        }
        cout << endl;
    }
    cout << endl;

    //print candidate key
    set<string> ck = getCandidateKey(G);
    for(auto l : ck){
        cout << l << " ";
    }


    return 0;
}