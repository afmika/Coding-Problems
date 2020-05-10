/*
Note: Try to solve this task in-place (with O(1) additional memory), since this is what you'll be asked to do during an interview.

You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

Example

For

a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]

the output should be

rotateImage(a) =
    [[7, 4, 1],
     [8, 5, 2],
     [9, 6, 3]]

*/
std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
    int n = a.size();
    vector<std::vector<int>> b;
    for (int y = 0; y < n; y++) {
        vector<int> c;
        for ( int x = 0; x < n; x++) {
            c.push_back( a[n - x - 1][y] );
        }
        b.push_back(c);
    }
    return b;
}
