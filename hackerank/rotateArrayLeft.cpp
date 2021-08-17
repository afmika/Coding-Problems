// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true
vector<int> rotateLeft(int k, vector<int> arr) {
    int l = arr.size();
    k %= l;
    if (l <=  1 || k == 0) return arr;
    
    int a[k], b[l - k];
    for (int i = 0; i < l; i++) {
        if (i < k) a[i] = arr[i];
        else b[i - k] = arr[i]; 
    }
    
    for (int i = 0; i < l; i++)
        arr[i] = i < (l - k) ? b[i] : a[i - l + k];

    return arr;
}