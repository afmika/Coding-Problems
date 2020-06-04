/**
 * @author afmika
 * Simple DFSearch example
 */

#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > dir = {
    {-1, 0}, // up
    {1, 0}, // down
    {0, -1}, // left
    {0, 1} // right
};

// display
void displayGrid( vector< vector<int> > glob) {
    for (auto i : glob) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

string makeStrPoints(vector<int> p) {
    return string( "["+to_string(p[0])+","+to_string(p[1])+"]" );
}

// tools
vector< vector<int> > cloneVector( vector<vector<int>> vec ) {
    vector< vector<int> > v;
    for (auto i : vec) v.push_back(i);
    return v;
}

vector< vector<int> > cloneMap( vector< vector<int> > glob) {
    vector< vector<int> > res;
    for (auto i : glob) {
        vector<int> tmp;
        for (auto j : i)
            tmp.push_back(j);
        res.push_back(tmp);
    }
    return res;
}

bool isEqual(vector<int> a, vector<int> b) {
    return a[0] == b[0] && a[1] == b[1];
}

bool isValidDir(vector<int> d, vector< vector<int> > global_map) {
    return d[0] >= 0 && d[0] < global_map.size() && d[1] >= 0 && d[1] < global_map.size();
}

vector< vector<int> > clonePath(vector< vector<int> > path) {
    vector< vector<int> > res;
    for (auto p : path) {
        res.push_back( p );
    }
    return res;
}

// algorithm
bool DFS(
         vector< vector< vector<int> > >& solutions,
         vector< vector<int> >& cur_sol,
         vector< vector<int> > global_map,
         vector< int > start,
         vector< int >  end
         ) {

    if ( isEqual(start, end) ) {
        return true;
    }


    for (auto d : dir) {
        vector<int> new_dir = {start[0] + d[0], start[1] + d[1] };
        // out of bound check
        if ( isValidDir(new_dir, global_map) ) {

            vector< vector<int> > cloned_map = cloneMap( global_map );
            vector< vector<int> > clone_cur_sol = cloneVector( cur_sol );

            if ( cloned_map[ new_dir[0] ][ new_dir[1] ] == 1  ) {
                // cout << makeStrPoints(new_dir) << endl;

                clone_cur_sol.push_back( new_dir );
                cloned_map[ new_dir[0] ][ new_dir[1] ] = 2; // pass

                if ( DFS(solutions, clone_cur_sol, cloned_map, new_dir, end ))
                    solutions.push_back( clone_cur_sol );

                // displayGrid(cloned_map);
            }
        }
    }
    return false;
}

vector< vector< vector<int> > >searchAllPaths(vector< vector<int> > global_map, vector<int> start, vector<int> end) {
    vector< vector< vector<int> > > solutions;
    vector< vector<int> > cur_sol;
    DFS(solutions, cur_sol, global_map, start, end);
    return solutions;
}

int main() {
    /*
    vector< vector<int> > global_map = {
         {1, 1, 0, 0, 0, 1},
         {0, 1, 0, 1, 1, 1},
         {0, 1, 1, 1, 0, 1},
         {0, 1, 0, 1, 0, 1},
         {0, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 0, 1}
    };
    */

    vector< vector<int> > global_map = {
         {1, 1, 0, 0, 0, 1},
         {0, 1, 0, 1, 0, 1},
         {0, 1, 1, 1, 0, 1},
         {0, 1, 0, 1, 0, 1},
         {0, 1, 0, 1, 1, 1},
         {1, 1, 1, 1, 0, 1}
    };

    // NOTE [y, x]
    vector< vector< vector<int> > > solutions = searchAllPaths( global_map, {0, 0}, {5, 5} );
    for (auto s : solutions) {
        cout << "Solution :" << endl;
        for (auto point : s) {
            cout << "[" << point[0] << "," << point[1] << "] ";
        }
        cout << endl;
    }
    return 0;
}
