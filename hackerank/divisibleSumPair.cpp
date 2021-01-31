// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, vector<int> ar) {
    int count = 0;
    int size = ar.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((ar[i] + ar[j]) % k == 0)
                count++;
        }
    }
    return count;
}