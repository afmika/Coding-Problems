#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'getMinCost' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY crew_id
 *  2. INTEGER_ARRAY job_id
 */

long getMinCost(vector<int> crew_id, vector<int> job_id) {
    sort(crew_id.begin(), crew_id.end());
    sort(job_id.begin(), job_id.end());
    int l = crew_id.size();
    long cost = 0;
    for (int i = 0; i < l; i++) {
        int pos = crew_id[i];
        int diff = abs(job_id[i] - pos);
        cost += (long) diff;
    }
    return cost;
}

int main() {
	vector<int> crew_id {3, 6, 9};
	vector<int> job_id {15, 1, 1};
	cout << getMinCost(crew_id, job_id);
	return 0;
}