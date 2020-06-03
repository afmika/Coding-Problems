#include <bits/stdc++.h>

using namespace std;

/*
Your assignment is to write a program that navigates a 2-dimensional board covered in coins which are picked up as you move over them, much like the game of Pac-Man.
Your program will take a single file input which contains 4 components: board_dimension , initial_position , movements , and walls.
Coins are in every position of the rectangular board except for the positions that have walls and the initial_position.
If Pac-Man is instructed to move into a wall (on the perimeter of the board or as defined by the walls input) it should have no effect (Pac-Man stays in place).

Program Input
Your program will take as input 4 parameters:

    board_dimension: array of two integers, is defined by X and Y coordinates, identifying the top right corner of the room rectangle - that is to say, [0,0] is in the bottom left corner,
    and (X,Y) is in the top right corner. This board is divided up in a grid based on
    these dimensions; a board that has dimensions X=5 and Y=5 has 5 columns and 5 rows for 25 possible positions.

    initial_position: array of two integers, is the initial position of Pac-Man in (x,y) coordinates.

    mouvements: string, are instructions in cardinal directions where e.g. N and E mean "go north" and "go east", respectively.
    The board is oriented facing north; thus, moving north from (0,0) lands Pac-Man at (0,1).

    walls: two-dimensional arrays of two integers, are the positions of walls on the board in (x,y) coordinates. Pac-Man cannot move through walls.

Example input values:
board_dimension = [5, 5]
initial_position = [1, 2]
mouvements = "NNESEESWNWW"
walls = [[1, 0], [2, 2], [2, 3]]

The above input should inform your program that you have a 5 x 5 board with walls
placed at positions [(1,0),(2,2),(2,3)] . Pac-Man will start at position (1,2) and will
"attempt" to move in the following sequence: N-N-E-S-E-E-S-W-N-W-W.

Program Output
Given the inputs described above, your program should return an array of three integers:

    Pac-Man's final location in X
    Pac-Man's final location in Y
    The number of coins that have been collected across all movements
    Example, matching the input above:
    return [1, 4, 7]

We will be testing edge cases on your code, so if there are any problems with the inputs, execution of the instructions, or any other cases you can think of, have your
pacman function return [-1, -1, 0]

    [execution time limit] 1 seconds (cpp)

    [input] array.integer board_dimension

    array of two integers, is defined by X and Y coordinates, identifying the top right corner of the room rectangle

    [input] array.integer initial_position

    array of two integers, is the initial position of Pac-Man in (x,y) coordinates

    [input] string mouvements

    string, are instructions in cardinal directions where e.g. N and E mean "go north" and "go east", respectively
    Possible direction: N, E, W, S

    [input] array.array.integer walls

    two-dimensional arrays of two integers, are the positions of walls on the board in (x,y) coordinates. Pac-Man cannot move through walls

    [output] array.integer
        [finalXposition, finalYposition, totalCoins]

*/
map<char, pair<int, int> > dir= {
    {'N' , {0, 1}}, // down
    {'S' , {0, -1}}, // up
    {'W' , {-1, 0}}, // left
    {'E' , {1, 0}}, // right
};

std::vector<int> TZWeek2ChallengePacman(
    std::vector<int> board_dimension,
    std::vector<int> initial_position,
    std::string mouvements,
    std::vector<std::vector<int>> walls
    )
{

    vector<int> dim = board_dimension;
    vector<int> pos = initial_position;
    int count = 0;
    int moved = false;
    vector<vector<int>> no_candies = { pos };
    for (char s : mouvements) {
        pair<int, int> d = dir[s];
        vector<int> n_pos = pos;
        n_pos[0] += d.first;
        n_pos[1] += d.second;

        if ( n_pos[0] < dim[0]
            && n_pos[1] < dim[1]
            && n_pos[0] >= 0
            && n_pos[1] >= 0 )
        {
            moved = true;
            bool is_coin = false;
            for (auto c : walls) {
                if ( c[0] == n_pos[0] && c[1] == n_pos[1]) {
                    is_coin = true;
                    break;
                }
            }
            bool candy = true;
            for(auto nc : no_candies) {
                if ( n_pos[0] == nc[0] && n_pos[1] == nc[1]) {
                    candy = false;
                    break;
                }
            }
            if ( !is_coin ) {
                pos = n_pos;
                if ( candy ) {
                    count++;
                    no_candies.push_back( n_pos );
                }
            }
        }
    }
    if ( moved )
        return vector<int>{pos[0], pos[1], count};
    return vector<int>{-1, -1, 0};
}


int main() {
    vector<int> res = TZWeek2ChallengePacman(
                {5,5}, {1,2}, "NNESEESWNWW",
                {{1,0}, {2, 2}, {2, 3}}
    );
    for (auto i : res) {
        cout << i << " ";
    }
    return 0;
}
