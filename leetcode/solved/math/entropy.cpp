class Solution {
public:
    double calculateEntropy(vector<int>& input) {
        unordered_map<int, double> P;
        
        for (int &in : input) P[in]++;
        
        double total = input.size(), s = 0;
        for (auto p : P) {
            double pi = p.second / total;
            s += pi * log(pi) / log(2.);
        }
        
        double d = fabs(s);
        if (d <= 10e-6) return 0;
        return -s;
    }
};