/*******
 * Read input from cin
 * Use cout << ... to output your result to STDOUT.
 * Use cerr << ... to output debugging information to STDERR
 * ***/
#include <bits/stdc++.h>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
   std::string line;
   unordered_map<int, unordered_set<int>> m;
   bool first = true;
	while (std::getline(std::cin, line))
	{
	    stringstream ss(line);
	    int a, b;
	    ss >> a >> b;
	    if ( first ) {
	        first = false;
	    } else {
	        if ( m.find(b) == m.end() ) {
	            m[b] = *(new unordered_set<int>());
	        }
            m[b].insert(a);
	    }
	}
    
    int root = 0;
    vector<int> level(10);
    for (auto p1 : m) {
        bool isChild = false;
        for (auto p2 : m) {
            if ( p2.second.find(p1.first) != p2.second.end() ) {
                isChild = true;
                break;
            }   
        }
        if ( !isChild ) {
            // cerr << "found e!";
            root = p1.first;
        }
    }
    // cerr << "Root is " << root << endl;
    int i = 0;
    level[i++] = 1;
    unordered_set<int> out = m[root];
    vector<int> current(out.begin(), out.end());
    while (true) {
        level[i++] = current.size();
        vector<int> nn;
        for (int node : current) {
            unordered_set<int> childs = m[node];
            for (int n : childs) {
                nn.push_back(n);
            }
        }
        // cerr << nn.size() << endl;
        if ( nn.size() == 0 )
            break;
        current = nn;
    }
    for (int i = 0; i < (int) level.size(); i++) {
        cout << level[i];
        if (i + 1 != level.size())
            cout << " ";
    }
	/* Vous pouvez aussi effectuer votre traitement une fois que vous avez lu toutes les données.*/
}