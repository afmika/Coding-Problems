/*******
 * Read input from cin
 * Use cout << ... to output your result to STDOUT.
 * Use cerr << ... to output debugging information to STDERR
 * ***/
#include <bits/stdc++.h>
#include "exercise.hpp"

using namespace std;

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
unordered_map<string, int> m;
int compXor(vector<int> key, int a, int b)  {
    string p0 = to_string(a) + "," + to_string(b);
    int res = 0;
    if ( m.find(p0) == m.end() ) {
        for (int ptr = a; ptr <= b; ptr++) {
            res ^= key[ptr];
            if (ptr > a) {
               string p = to_string(a) + "," + to_string(ptr);
               m[p] = res;                
            }
        }
        m[p0] = res;
    } else {
        res = m[p0];
    }    
    return res;
}
void ContestExerciseImpl::main() {
   std::string line;
   int line_count = 0;
   vector<int> key;
   vector<pair<int,int>> msg;
   	int kl, msgl;
   	bool first = true, fetch_key = true;
	vector<int> out(256);
	while (std::getline(std::cin, line))
	{
	    stringstream ss(line);
	    if ( first ) {
	        first = false;
	        ss >> kl >> msgl;
	    } else {
	        if ( kl > 0 ) {
	            while (kl > 0) {
	                int v;
	                ss >> v;
	                key.push_back(v);
	                kl--;
	            }
	        } else {
                int a, b;
                ss >> a >> b;
                int res = compXor(key, a, b);
                out[res]++;
	        }
	    }
	}
    for (int i = 0; i < (int) out.size(); i++) {
        cout << out[i];
        if ( i + 1 < out.size() ) 
            cout << " ";
    }
	/* Vous pouvez aussi effectuer votre traitement une fois que vous avez lu toutes les données.*/
}