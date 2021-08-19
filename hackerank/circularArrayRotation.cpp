// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true
vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    int l = a.size();
    k %= l;
    vector<int> res;
    for (int q : queries)
        res.push_back(a[(l - k + q) % l]);
    return res;
}
