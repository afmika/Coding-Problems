#include <bits/stdc++.h>

// https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem
using namespace std;

vector<int> dir {-1, 1, 0}; // 3 x 3 = 9 dir

bool isOk (vector<vector<int>> &m, int y, int x) {
    return m.size() > y && y >= 0
        && m[0].size() > x && x >= 0;
}

int dfs (vector<vector<int>> &m, int y, int x, int c) {
    int count = 0;
    for (int dy : dir) {
        for (int dx : dir) {
            int ny = y + dy;
            int nx = x + dx;
            if (isOk(m, ny, nx) && m[ny][nx] == 1) {
                m[ny][nx] = 0;
                count = max (count, dfs (m, ny, nx, c + 1));
                m[ny][nx] = 1; 
            }
        }
    }
    return max(c, count);
}

int connectedCell(vector<vector<int>> &matrix) {
    int nax = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                matrix[i][j] = 0;
                nax = max(nax, dfs(matrix, i, j, 1));
                matrix[i][j] = 1;
            }
        }
    }
    return nax;
}

int main () {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m);
    for (int i = 0; i < m; i++) {
        matrix[i] = vector<int>(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << connectedCell(matrix);
    return 0;
}
