int birthdayCakeCandles(vector<int> candles) {
    unordered_map<int, int> count;
    int nax = -1;
    for (int n : candles) {
        count[n]++;
        nax = max(nax, n);
    }
    return count[nax];
}