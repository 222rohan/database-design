#include "dbdesign.h"
#include <bits/stdc++.h>
using namespace std;


set<string> closure(set<string> X, vector<pair< set<string> , set<string> >> fdSet){
    set<string> closure;
    closure = X;
  
  //go through fdSet and find all attributes which can be reached trhough X
    //add them to closure
    //repeat until closure does not change
    bool change = true;
    while(change){
        change = false;
        for(auto fd : fdSet){
            if(includes(closure.begin(), closure.end(), fd.first.begin(), fd.first.end())){
                if(!includes(closure.begin(), closure.end(), fd.second.begin(), fd.second.end())){
                    closure.insert(fd.second.begin(), fd.second.end());
                    change = true;
                }
            }
        }
    }
    return closure;
}