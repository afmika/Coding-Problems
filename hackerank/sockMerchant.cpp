int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> socks;
    int pairs = 0;
    for (int &v : ar) {
        socks[v]++;
		pairs += (1 + socks[v]) % 2;
        // if (socks[v] % 2 == 0) {
            // pairs++;
            // socks[v] = 0;
        // }
    }
    return pairs;
}