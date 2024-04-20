#include "dbdesign.h"
#include <bits/stdc++.h>
using namespace std;

//module 1: closure of a set of attributes
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

//module 2: find the minimal cover of an fdSet
vector<pair< set<string> , set<string> >> minimalCover(vector<pair< set<string> , set<string> >> fdSet){
    vector<pair< set<string> , set<string> >> minimalCover;

    //step 1: split rhs to size one and add all fds
    for(auto fd : fdSet){
        for(auto rhs : fd.second){
            minimalCover.push_back({fd.first, {rhs}});
        }
    }

    //step 2: remove extraneous attributes from lhs
    bool change = true;
    while(change){
        change = false;
        for(auto fd : minimalCover){
            set<string> lhs = fd.first;
            set<string> rhs = fd.second;
            for(auto l : lhs){
                set<string> temp = lhs;
                temp.erase(l);
                set<string> closureTemp = closure(temp, minimalCover);
                if(closureTemp.find(*rhs.begin()) != closureTemp.end()){
                    minimalCover.erase(find(minimalCover.begin(), minimalCover.end(), fd));
                    minimalCover.push_back({temp, rhs});
                    change = true;
                    break;
                }
            }
        }
    }

    //step 3: remove redundant fds
    for(auto fd : minimalCover){
        vector<pair< set<string> , set<string> >> temp = minimalCover;
        temp.erase(find(temp.begin(), temp.end(), fd));
        set<string> closureTemp = closure(fd.first, temp);
        if(closureTemp.find(*fd.second.begin()) != closureTemp.end()){
            minimalCover.erase(find(minimalCover.begin(), minimalCover.end(), fd));
        }
    }
    return minimalCover;
}

//module 3: test for 2NF

//get key
set<string> getCandidateKey(vector<pair< set<string> , set<string> >> minFdSet){
    set<string> candidateKey;
set<string> attributes;
for(auto fd : minFdSet){
    attributes.insert(fd.first.begin(), fd.first.end());
    attributes.insert(fd.second.begin(), fd.second.end());
}
for(auto a : attributes){
    set<string> temp = attributes;
    temp.erase(a);
    set<string> closureTemp = closure(temp, minFdSet);
    if(closureTemp != attributes){
        candidateKey.insert(a);
    }
}

    return candidateKey;
}
