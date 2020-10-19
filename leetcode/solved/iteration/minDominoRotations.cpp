/*
Minimum Domino Rotations For Equal Row

In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

 

Example 1:

Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.

Example 2:

Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
*/
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int l = A.size();
        int best = INT_MAX;
        for (int n = 1; n <= 6; n++ ) {
            int swap_A = 0, swap_B = 0, i = 0;
            int ok_A = 0, ok_B = 0;
            
            while ( i < l ) {
                bool can = false;
                if ( A[i] == n || A[i] != n && B[i] == n ) {
                    ok_A++;
                    if (A[i] != n && B[i] == n)
                        swap_A++;
                    can = true;
                }
                if ( B[i] == n || B[i] != n && A[i] == n ) {
                    ok_B++;
                    if (B[i] != n && A[i] == n)
                        swap_B++;
                    can = true;
                }
                if ( !can )
                    break;
                i++;
            }
            if ( ok_A == l )
                best = min(swap_A, best);
            if ( ok_B == l )
                best = min(swap_B, best);
        }
        
        return best == INT_MAX ? -1 : best;
    }
}; 