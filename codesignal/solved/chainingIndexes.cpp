// this needs a further optimisation
int cycle (int start, vector<int> &arr) {
	int n = start;
	int count = -1;
	while (true) {
        if (arr[n] < 0) break;
        int p = n;
		n = arr[n];
        arr[p] = -1;
		count++;
	}
	return count;
}

int chainingIndexes (vector<int> arr) {
	int nax = -1;
    unordered_set<int> s (arr.begin(), arr.end());
    vector<int> *candidates = new vector<int>, *normal = new vector<int>;

    for (int i = arr.size() - 1; i >= 0; i--) {
        vector<int> *target = s.find(i) != s.end() ? normal : candidates;
        target->push_back(i);
    }
    // this order is very important
    for (int &i : *candidates)
		nax = max(nax, cycle (i, arr));
    for (int &i : *normal)
		nax = max(nax, cycle (i, arr));
	
	delete candidates;
	delete normal;
	
	return nax;
}
