//package which contains modules to create a good database design
//given a relational schema and a set of functional dependencies
//modules 1. closure
//        2. minimal cover
//        3. test for 2NF (no partial dependencies) with decomposition
//        4. test for 3NF (no transitive dependencies) with decomposition
//        5. check for lossless join

#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

//module 1: closure
set<string> closure(set<string> attributes, vector<pair< set<string> , set<string> >> fdSet);
vector<pair< set<string> , set<string> >> minimalCover(vector<pair< set<string> , set<string> >> fdSet);