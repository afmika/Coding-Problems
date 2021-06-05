// https://www.hackerrank.com/challenges/kangaroo/problem
string kangaroo(int x1, int v1, int x2, int v2) {
    // note : x1 < x2
    // x1 + j*v1 = x2 + j*v2 
    // j*(v1 - v2) = x2 - x1
    // j = (x2 - x1) / (v1 - v2)
    // j should be an integer
    int dx = (x2 - x1), dv = (v1 - v2);
    if (dv <= 0) return "NO";
    return dx % dv == 0 ? "YES" : "NO"; 
}