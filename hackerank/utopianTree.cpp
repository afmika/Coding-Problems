// https://www.hackerrank.com/challenges/utopian-tree/problem
int utopianTree(int n) {
    int h = 1;
    for (int i = 0; i < n; i++)
        h = i % 2 == 0 ? h * 2 : h + 1;
    return h;
}