/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

 

Constraints:

    1 <= candidates.length <= 30
    1 <= candidates[i] <= 200
    Each element of candidate is unique.
    1 <= target <= 500


*/
#include <bits/stdc++.h>

using namespace std;

map<int, bool> pass;

set<pair<int, int>> cloneSet(set<pair<int, int>> v) {
    set<pair<int, int>> res;
    for (auto i : v ) {
        res.insert(i);
    }
    return res;
}

void dfs(
        set<set<pair<int, int>>>& solutions, 
        vector<int>& candidates, 
        set<pair<int, int>> current, 
        int current_sum, 
        int target
    ) {

    if ( current_sum >= target ) {
        if ( current_sum == target ) {
            solutions.insert(current);
        }
        return;
    }

    for (int n : candidates) {
        if ( !pass[n] ) { 
            pass[n] = true;
            int div = target / n;
            for (int k = div; k >= 1; --k) { 
                set<pair<int, int>> clone = cloneSet(current);
                clone.insert({k, n});
                dfs(solutions, candidates, clone, current_sum +  k * n, target);
            }
            pass[n] = false;
        }
    }
}


vector<vector<int>> constructSolution(set<set<pair<int, int>>> solutions){
    vector<vector<int>> final_sol;
    for (auto s : solutions) {
        vector<int> temp;
        for (auto n : s) {
            int times = n.first;
            int value = n.second;
            for (int t = 0; t < times; t++) {
                temp.push_back(value);
            }
        }
        final_sol.push_back(temp);
    } 
    return final_sol;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    for (int n : candidates ) {
        pass[n] = false;
    }    
    set<set<pair<int, int>>> solutions;
    set<pair<int, int>> temp;
    dfs(solutions, candidates, temp, 0, target);
    return constructSolution(solutions);
}

int main() {
    vector<int> cand {2, 3, 6, 7, 3};
    vector<vector<int>> solutions = combinationSum(cand, 30);
    cout << solutions.size() << "\n"; 
    for (auto solution : solutions) {
        for (int s : solution) {
            cout << s << " ";
        }
        cout << "\n";
    }
    return 0;
}
