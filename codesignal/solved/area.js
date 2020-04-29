/*
Below we will define an n-interesting polygon. Your task is to find the area of a polygon for a given n.

A 1-interesting polygon is just a square with a side of length 1. 
An n-interesting polygon is obtained by taking the n - 1-interesting polygon and appending 
1-interesting polygons to its rim, side by side. 
You can see the 1-, 2-, 3- and 4-interesting polygons in the picture below.

n = 1
 *

n = 2
 *
***
 *

 
n = 3
    *
  * * *
* * * * *
  * * *
    *
	
n = 4
      *
    * * *
  * * * * *
* * * * * * *
  * * * * *
    * * *
	  *
	  
*/

/**
 let's just take it easy...
 **/
function shapeArea(n) {
    if ( n == 1 ) {
        return 1;
    }
	// n = 1 , perimter = 0
	// n = 2 , perimeter = 4
	// n = 3 , perimeter = 8
	// n = 4, perimeter = 12
	// ....
    // n, perimeter = 4 * (n-1)
	// tot_surface = perimeter + areaOfThepreviousN
	// bruuuh
    return 4 * (n-1) + shapeArea(n - 1);
}

console.log( shapeArea(4))