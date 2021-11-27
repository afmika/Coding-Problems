#include <stdio.h>

inline int min (int a, int b) { return a < b ? a : b; }
inline int min3 (int a, int b, int c) { return min(min(a, b), c); }

inline int forPos (int n, int L, int y, int x) {
	// distance from the center
    return 1 + n - min3(min(y, x) + 1, L - y, L - x);
}

int main() {
    int n; // layer
    scanf("%d", &n);
    int L = 2*n - 1;
    for (int y = 0; y < L; y++) {
        for (int x = 0; x < L; x++)
            printf("%d ", forPos(n, L, y, x));
        printf("\n");
    }
    return 0;
}