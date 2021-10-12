int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> socks;
    int pairs = 0;
    for (int &v : ar) {
        socks[v]++;
        if (socks[v] % 2 == 0 && socks[v] != 0) {
            pairs++;
            socks[v] = 0;
        }
    }
    return pairs;
}