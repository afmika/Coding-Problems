class Solution {
public:
    vector<vector<int>> solutions; 
    vector<int> current;
    void solve(vector<int>& arr, int n, int sum , int index) {
        if(sum <= 0) {
            if(sum == 0)
                solutions.push_back(current);
            return;
        }
        for(int i = index; i < n ; i++) {
            const int left = sum - arr[i];
            current.push_back(arr[i]);
            solve(arr, n, left, i);
            current.pop_back();
			// arr is sorted so we can assume we wont get it
            if(left < 0)
                return;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int sum) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        solve(arr, n, sum, 0);
        return solutions;
    }

};