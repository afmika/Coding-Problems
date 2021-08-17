// https://www.hackerrank.com/challenges/sparse-arrays/problem
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    vector<int> res (queries.size());
    int p = 0;
    unordered_multiset<string> s (strings.begin(), strings.end());
    for (string &q : queries)
        res[p++] = s.count(q);
    return res;
}
