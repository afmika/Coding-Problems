/*
/*
Hard

On a 2-dimensional grid, there are 4 types of squares:

    1 represents the starting square.  There is exactly one starting square.
    2 represents the ending square.  There is exactly one ending square.
    0 represents empty squares we can walk over.
    -1 represents obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
*/
*/
class Solution {
public:
    vector< vector<int> > dir = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    vector< vector<int> > makeClone(vector<vector<int>>& grid) {
        vector<vector<int>> clone;
        for (auto row : grid) {
            vector<int> cl;
            for (auto col : row) cl.push_back(col);
            clone.push_back(cl);
        }
        return clone;
    }

    void showGrid(vector<vector<int>>& grid) {
        cout << endl;
        for (auto row : grid) {
            for (auto col : row) cout << col << " ";
            cout << endl;
        }
    }


    bool areEqual(vector<int> a, vector<int> b) {
        return a[0] == b[0] && a[1] == b[1];
    }

    bool isValid(vector<int> pos, vector<vector<int>> grid) {
        return pos[0] >= 0 && pos[1] >= 0 && pos[0] < grid.size() && pos[1] < grid[0].size();
    }

    bool DFS (
              vector< vector< vector<int> > >& solutions,
              vector< vector<int> > current,
              vector<int> pos,
              vector<int> end,
              vector<vector<int>> grid
            )
    {
		if ( areEqual(pos, end) ) {
			return true;
		}
		for (auto d : dir) {
			vector<int> new_dir = {
				pos[0] + d[0],
				pos[1] + d[1]
			};
			if ( isValid(new_dir, grid) ) {
				int y = new_dir[0], x = new_dir[1];
				int value = grid[ y ] [ x ];

				if ( grid[y][x] == 0 || grid[y][x] == 2 ) {
					grid[ y ] [ x ] = 7;
					vector< vector<int> > clone_current = makeClone( current );
					clone_current.push_back(new_dir);
					if ( DFS (solutions, clone_current, new_dir, end, grid) ) {
						solutions.push_back( clone_current );
					}
				}
				grid[ y ] [ x ] = value;
			}
		}

		return false;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<int> start;
        vector<int> end;
        int n_empty = 0;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[y].size(); x++) {
                if ( grid[y][x] == 1 ) {
                    start = {y, x};
                }
                if ( grid[y][x] == 2 ) {
                    end = {y, x};
                }
                if ( grid[y][x] == 0 ) {
                    n_empty++;
                }
            }
        }


        vector< vector< vector<int> > > solutions;
        vector< vector<int> > current;

        DFS (solutions, current, start, end, grid);
        int total = 0;
        for (auto sol : solutions) {
            int n = sol.size() - 1;
            if ( n == n_empty ) {
                total++;
            }
        }
        return total;
    }
};