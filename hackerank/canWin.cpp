// Java 1D Array (Part 2)
// https://www.hackerrank.com/challenges/java-1d-array/problem

public class Solution {
    public static boolean dfsSolve (int i, int leap, int[] game, int n) {
        if (i < 0 || game[i] == 1) return false;
        if (i + 1 == n || i + leap >= n) return true;
        game[i] = 1;
        int[] deltas = {1, -1, leap};
        for (int delta : deltas)
            if (dfsSolve(i + delta, leap, game, n))
                return true;
        return false;
    }
    public static boolean canWin(int leap, int[] game) {
        return dfsSolve(0, leap, game, n);
    }
}