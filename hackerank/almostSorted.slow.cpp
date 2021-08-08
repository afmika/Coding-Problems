bool isSorted (vector<int> arr) {
    for (int i = 1; i < (int) arr.size(); i++) {
        if (arr[i - 1] > arr[i])
            return false;
    }
    return true;
}
vector<int> findUnsortedIndexes (vector<int> arr) {
    vector<int> indexes;
    for (int i = 1; i < (int) arr.size(); i++) {
        if (arr[i - 1] > arr[i]) {
            indexes.push_back(i - 1);
            indexes.push_back(i);
            i++;
        }
    }
    return indexes;
}
void almostSorted(vector<int> arr) {
    if (isSorted(arr)) {
        cout << "yes";
        return;
    }
    vector<int> unsorted = findUnsortedIndexes (arr);
    int s =  (int) unsorted.size();
    for (int idx = 0; idx < s; idx++) {
        int i = unsorted[idx];
        for (int idx_j = idx + 1; idx_j < s; idx_j++) {
            int j = unsorted[idx_j];
            // try swap
            swap(arr[i], arr[j]);
            if (isSorted(arr)) {
                printf("yes\nswap %i %i", i + 1, j + 1);
                return;
            }
            swap(arr[i], arr[j]);
            
            // try reverse
            reverse (arr.begin() + i, arr.begin() + j + 1);
            if (isSorted(arr)) {
                printf("yes\nreverse %i %i", i + 1, j + 1);
                return;
            }
            reverse (arr.begin() + i, arr.begin() + j + 1);
        }
    }
    printf("no");
}