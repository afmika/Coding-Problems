// https://www.hackerrank.com/challenges/counting-valleys/problem
int countingValleys(int steps, string path) {
    int level = 0, c = 0;
    for(int i = 0; i < steps; i++) {
        if (path[i] == 'D') {
            level--;
        } else {
            if (++level == 0) c++;
        }
    }
    return c;
}
