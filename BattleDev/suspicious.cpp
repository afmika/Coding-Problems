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
   bool first = true;
   int count = 0;
   int total = 0;
	while (std::getline(std::cin, line))
	{
	    stringstream ss(line);
	    string v;
	    ss >> v;
	    if ( first ) {
	        first = false;
	    } else {
	        total++;
	        string first = v.substr(0, 2);
	        if (first[0] == '2' || first[0] == '0' && first[1] <= '7' ) {
	            count++;
	        }
	    }
		/*Lisez les données ici et effectuez votre traitement ici */
	}
	
	if ( count >= total / 2) {
	    cout << "SUSPICIOUS";
	} else {
	    cout << "OK";
	}

	/* Vous pouvez aussi effectuer votre traitement une fois que vous avez lu toutes les données.*/
}