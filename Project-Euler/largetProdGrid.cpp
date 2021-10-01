#include <bits/stdc++.h>

using namespace std;

int doProd (int chainMax, int currY, int currX, vector<vector<int>> &grid) {
    int q = chainMax;
    int n = grid.size(); // square
    
    int h_left = 1, h_right = 1, v_up = 1, v_down = 1,
        d_down_right = 1, d_down_left = 1,
        d_up_left = 1, d_up_right = 1;
    
    for (int d = 0; d < q; d++) {
        // horiz
        if (currX + q  < n) h_right *= grid[currY][currX + d];
        if (currX - q >= n) h_left  *= grid[currY][currX - d];
        
        // vert
        if (currY + q  < n) v_down  *= grid[currY + d][currX];
        if (currY - q >= 0) v_up    *= grid[currY - d][currX];
        
        // diag
        if (currX + q < n  && currY + q < n ) d_down_right *= grid[currY + d][currX + d];
        if (currX - q >= 0 && currY + q < n ) d_down_left  *= grid[currY + d][currX - d];
        if (currX - q >= 0 && currY - q >= 0) d_up_left    *= grid[currY - d][currX - d];
        if (currX + q < n  && currY - q >= 0) d_up_right   *= grid[currY - d][currX + d];
    }
    
    return max({
        h_left, h_right, v_up, v_down, d_down_right, d_down_left, d_up_left, d_up_right
    });
}

int solve (int chainMax, vector<vector<int>> &grid) {
    int largest = -1;
    
    for (int i = 0; i < (int) grid.size(); i++)
        for (int j = 0; j < (int) grid.size(); j++)
            largest = max (doProd(chainMax, i, j, grid), largest);
	
    return largest;
}

int main() {
    // use largestProdGrid-data.txt
    int n = 20;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++) {
        grid.push_back (vector<int>(n));
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    
    cout << solve (4, grid);
    return 0;
}
