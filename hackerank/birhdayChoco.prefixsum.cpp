/**
 * @author afmika
 */
//Challenge :  https://www.hackerrank.com/challenges/the-birthday-bar/problem

int birthday(vector<int> s, int d, int m) {
    int conseq = m;
    int sum = d;
    int n = s.size ();
    // a1 a2 a3 a4
    // a1 (a1 + a2) (a1 + a2 + a3) .... (a1 + a2 + .... aN)
    int prefix[n];
    prefix[0] = s[0];
    int count = 0;
    if (conseq == 1 && sum == s[0]) count++;
    for (int i = 1; i < n; i++) {
        if (conseq == 1 && sum == s[i]) count++;
        prefix[i] = prefix[i - 1] + s[i];
    }
    
    if (conseq == 1) return count;
    
    for (int i = 0; i < n; i++) {
        int j = -1 + i + conseq;
        if (j < n) {
            int curr_sum = prefix[j] - prefix[i] + s[i];
            if (curr_sum == sum) count++;
        }
    }
    return count;
}