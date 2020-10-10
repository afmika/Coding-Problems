/*

Picture a map of a battlefield divided into two halves. Points which lie to the left of the line x = 0 are on the forest free side, while points which lie on or to the right of the line are in the forest.

Your army needs to get from point a to point b. The problem is that while point a is located on the forest free side where your army's speed equals v1 miles per hour, point b is located in the forest, where your speed reduces to v2 miles per hour.

Calculate the shortest possible travel time for your army to reach point b.

Example

For a = [-1.5, 0.5], b = [1.5, 1.5], v1 = 4.4, and v2 = 1.1, the output should be
armyMarch(a, b, v1, v2) = 1.761942

 * */
#include <bits/stdc++.h>

using namespace std;


double timeTravel(vector<double> a, vector<double> b, double v) {
	double dist = sqrt( pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2) );
	return dist / v;
}

double armyMarchLI(std::vector<double> a, std::vector<double> b, double v1, double v2) {
	double cur_dist = 10e7;
    double ay = a[1], by = b[1];
	vector<double> pt = {0, ay};
	double delta_y = ay - by;
	
	if ( delta_y == 0 )
		return timeTravel(a, pt, v1) + timeTravel(pt, b, v2);
	
	double dy = 0.01 * (delta_y < 0 ? 1 : -1);	
	while ((delta_y < 0 && pt[1] <= by) || (delta_y > 0 && pt[1] > by)) {
		cur_dist = min(cur_dist, timeTravel(a, pt, v1) + timeTravel(pt, b, v2));
		pt[1] += dy;
	}
	return cur_dist;
}

int main() {
	vector<double> a {-150, 0.5}, b{150, 15};
	double v1 = 4.4, v2 = 1.1;
	cout << armyMarchLI(a, b, v1, v2) << endl;

	return 0;
}
