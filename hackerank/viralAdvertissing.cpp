// https://www.hackerrank.com/challenges/strange-advertising/problem
int viralAdvertising(int n) {
    int c = 0, s = 5, curr = 0;
    for (int i = 0; i < n; i++, s *= 3){
        s /= 2;
        curr += s;
    }
    return curr;
}