/*******
 * Read input from cin
 * Use cout << ... to output your result to STDOUT.
 * Use cerr << ... to output debugging information to STDERR
 * ***/
#include <iostream>
#include <limits>
#include <sstream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
   std::string line;
   bool first = true;
   int suspects = 0;
   
	while (std::getline(std::cin, line))
	{
	    if ( first ) {
	        first = false;
	    }  else {
			int l = line.size();
	        if ( l >= 5 ) {
	            int ok = true;
	            for (int i = l - 5; i < l; i++) {
	                if ( !(line[i] >= '0' && line[i] <= '9') ) {
	                    ok = false;
	                    break;
	                }
	            }
    	        if ( ok ) suspects++;
	        }
	    }
		/*Lisez les données ici et effectuez votre traitement ici */
	}
    cout << suspects;
	/* Vous pouvez aussi effectuer votre traitement une fois que vous avez lu toutes les données.*/
}