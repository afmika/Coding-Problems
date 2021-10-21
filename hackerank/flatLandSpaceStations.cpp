https://www.hackerrank.com/challenges/flatland-space-stations/problem
int flatlandSpaceStations(int n, vector<int> &c) {
    int nax = 0;
    for (int i = 0; i < n; i++) {
        int shortest = INT_MAX;
        for (int station : c) {
            int d = abs(station - i);
            shortest = min(shortest, abs(station - i));
            if (d == 0) break;
        }
        nax = max(nax, shortest);
    }
    return nax;
}