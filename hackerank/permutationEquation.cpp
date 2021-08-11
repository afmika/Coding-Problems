// https://www.hackerrank.com/challenges/permutation-equation/problem
vector<int> permutationEquation(vector<int> p) {
    int n = (int) p.size ();
    
    unordered_map<int, int> indexOf;
    for (int i = 0; i < n; i++)
        indexOf[p[i]] = i + 1;
    
    vector<int> res;
    for (int x = 1; x <= n; x++) {
        int tmp = indexOf[x]; // x == p(tmp)
        int tmp2 = indexOf[tmp]; // tmp == p(tmp2) => x == p(tmp) == p(p(tmp2))
        res.push_back(tmp2);
    }
    return res;
}