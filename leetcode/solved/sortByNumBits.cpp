class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int da = hammingWeight(a); 
            int db = hammingWeight(b);
            if ( da == db ) {
                return a < b;
            }
            return da < db;
        });
        return arr;
    }
};
