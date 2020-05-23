#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > dir = {
    {-1, 0}, // up
    {1, 0}, // down
    {0, -1}, // left
    {0, 1} // right
};

string makeStrPoints(vector<int> p) {
    return string( "<"+to_string(p[0])+","+to_string(p[1])+">" );
}

bool DFS(
         vector< string >& result,
         vector< vector<int> > global_map,
         vector< int > start,
         vector< int >  end,
         vector< int >  direction
         ) {

    if ( result.size() == 0) {
        result.push_back( makeStrPoints( start ) );
    }


    int max_p = global_map.size();
    if ( start[0] == end[0] && start[1] == end[1]) {
        return true;
    }

    int y = direction[0] + start[0];
    int x = direction[1] + start[1];

    vector< string > current_path;
    // first we need to check if it is a valid position
    if ( x >= 0 && y >= 0 && x < max_p && y < max_p ) {
        if ( global_map[y][x] ) {
            // this direction leads us to a case == 1
            current_path.push_back(  makeStrPoints({y, x}) );
            for ( auto d : dir ) {
                // start <- new_dir
                vector < int > new_dir = {d[0] + y, d[1] + x };
                // new_dir[0] != start[0] || new_dir[1] != start[1]
				// cooler version :p
                if ( new_dir[0] ^ start[0] | new_dir[1] ^ start[1] ) {
                    if ( DFS ( current_path, global_map, {y, x}, end, d) ) {
                        for ( auto st : current_path ) {
                            result.push_back( st );
                        }
                        // meaning this route leads us to the real target : end
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

vector<string> searchPath(vector< vector<int> > global_map, vector< int > start, vector< int >  end) {
    vector< string > result;
    bool found = false;
    for ( auto d : dir ) {
        if ( DFS ( result, global_map, start, end, d) ) {
            found = true;
            break;
        }
    }
    cout << "PATH ";
    if ( ! found ) {
        cout << "NOT";
        result.clear();
    }
    cout << " FOUND !" << endl;
    return result;
}




int main() {
    vector< vector<int> > global_map = {
         {1, 1, 0, 0, 0, 0},
         {0, 1, 0, 1, 1, 1},
         {0, 1, 0, 1, 0, 1},
         {0, 1, 0, 1, 0, 1},
         {0, 1, 0, 1, 1, 1},
         {0, 1, 1, 1, 0, 1}
    };

    vector< string > points = searchPath( global_map, {0, 0}, {5, 5} );
    for (auto c : points) {
        cout << c << endl;
    }
    return 0;
}
