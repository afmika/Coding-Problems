#include <bits/stdc++.h>

using namespace std;

float d2 (vector<float> a, vector<float> b) {
    float s = 0;
    for (int i = 0; i < (int) a.size(); i++) {
        s += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return s;
}

struct Point {
    float d;
    int idx;
    Point (float d, int idx) {
        this->d = d;
        this->idx = idx;
    }
};

int main() {
    int d, a, k, i;
    cin >> d >> a >> k >> i;
    vector<vector<float>> points;
    while (d--) {
        vector<float> point;
        int k = 0;
        while (k < a) {
            float t;
            cin >> t;
            point.push_back(t);
            k++;
        }
        points.push_back(point);
        
    }
    
    vector<Point> pts;
    vector<float> intr = points[i];
    
    for (int j = 0; j <(int) points.size(); j++) {
        if (i == j) continue;
        float d = d2(intr, points[j]);
        Point pt = Point(d, j);
        pts.push_back(pt);
    }
    
    sort(pts.begin(), pts.end(), [&] (auto a, auto b) {
        if (a.d != b.d) return a.d < b.d;
       return a.idx < b.idx; 
    });
    
    for (int j = 0; j < k ;j++) {
        cout << pts[j].idx << (j + 1 == k ? "" : " ");
    }
    
    return 0;
}
