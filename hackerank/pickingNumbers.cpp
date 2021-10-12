int pickingNumbers(vector<int> &a) {
    // ordered map
    map<int, int> count;
	
	// just get the frequency
	// gaps should be 0 by default
    for (int n : a) count[n]++;
    int nax = 0;
    for (int i = 1, s = a.size(); i < s; i++) {
		// max (for a number i : total occ curr for + total occ next)
        nax = max(nax,  count[i - 1] + count[i]);
    }
    return nax;
}