// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
string catAndMouse(int x, int y, int z) {
    int dx = abs(z - x), dy = abs(z - y);
    if (dx == dy) return "Mouse C";
    return dx == max (dx, dy) ? "Cat B" : "Cat A";
}