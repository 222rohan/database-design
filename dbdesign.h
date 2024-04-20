//package which contains modules to create a good database design
//given a relational schema and a set of functional dependencies
//modules 1. closure
//        2. minimal cover
//        3. test for 2NF (no partial dependencies) 
//        4. test for 3NF (no transitive dependencies) 
//        5. decomposition in case of violation of 2NF or 3NF
//        6. check for lossless join

#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

//module 1: closure
set<string> closure(set<string> attributes, vector<pair< set<string> , set<string> >> fdSet);

//module 2: minimal cover
vector<pair< set<string> , set<string> >> minimalCover(vector<pair< set<string> , set<string> >> fdSet);

//module 3: 2NF check
set<string> getCandidateKey(vector<pair< set<string> , set<string> >> minFdSet);
bool is2NF(vector<pair< set<string> , set<string> >> minFdSet);

//module 4: 3NF check
bool is3NF(vector<pair< set<string> , set<string> >> minFdSet);