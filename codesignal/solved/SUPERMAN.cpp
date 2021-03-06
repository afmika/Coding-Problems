#include <bits/stdc++.h>
using namespace std;
/*
Krypton is on the verge of destruction, Kal-El (baby superman) must be sent to Earth if we want to have a chance of survival of the kryptonians.

Earth is very far from Krypton and the small spaceship Kal-El is sent in would not have enough fuel to do the travel in one go directly from Krypton to Earth without refuelling.

Fortunately, the allies of the kryptonians have built many fuelling stations sparsed in space and each of which is relatively close to its neighboring station(s).

You must program Kal-El's spaceship to travel to the closest station and refuel while still going towards Earth. The number of crossed stations doesn't matter, Kal-El just have to arrive on Earth while the distance between two objects (stations or planets) is minimized. But if there are multiple ways where the max distance between two objects is the same, take the one with smaller min distance between two objects, and if there is still a tie, take the one with the smaller total distance of the trip.

Inputs

    earthCoordinates: a 3 Dimension coordinates of type integer in the format of [x, y, z], it's the coordinates of Earth relative to Krypton, meaning Krypton's coordinates is given as (always) [0, 0, 0]
    fuelingStationsCoordinates: a list of 3D coordinates of type integer, it's the list of all the coordinates of the fuelling stations relative to Krypton

Output
An array of floats of the format [a, b, c] where:

    a: is the total distance that Kal-El's spaceship has travelled on his journey from Krypton to Earth while refuelling on some (or all or none) fuelling stations.
    b: is the largest distance between two fuelling stations that Kal-El's spaceship had to travel through on his journey, or between a planet and a fuelling station.
    c: is the smallest distance between two fuelling stations that Kal-El's spaceship had to travel through on his journey, or between a planet and a fuelling station.

Important: Round each number of the output to 2 decimal places Half-Up


Input:

earthCoordinates: [2, 2, 2]
fuelingStationsCoordinates: [[1,1,1]]

Expected Output:

[3.46, 1.73, 1.73]

Input:

earthCoordinates: [2, 2, 2]
fuelingStationsCoordinates:
[[0,0,2],
 [0,2,2],
 [2,0,0]]

Expected Output:

[6, 2, 2]


earthCoordinates: [23, 21, 26]
fuelingStationsCoordinates:
[[-20,3,-20],
 [2,21,11],
 [19,-1,-27],
 [-26,-25,6],
 [5,18,-26],
 [-18,27,-26]]

Expected Output:

[49.6, 25.81, 23.79]
*/
typedef struct Node {
    vector<int> coord;
    bool isEarth;
    Node();
    Node(vector<int> c, bool isEarth) {
        this->coord = c;
        this->isEarth = isEarth;
    }
} Node;

typedef struct ResultItem {
    double tot_dist;
    double max_delta;
    double min_delta;
    ResultItem(double tot_dist, double max_delta, double min_delta) {
        this->tot_dist = tot_dist;
        this->max_delta = max_delta;
        this->min_delta = min_delta;
    }
    void display() {
        printf("%f %f %f\n", tot_dist, max_delta, min_delta);
    }
} ResultItem;

double dist(vector<int> a, vector<int> b) {
    double sDist = 0;
    for (size_t c = 0; c < a.size(); c++) sDist += pow(a[c] - b[c], 2);
    return sqrt((double) sDist);
}

double distOrigin(vector<int> a) {
    return dist(a, vector<int>{0, 0, 0} );
}

vector< vector<int> > clonePath(vector< vector<int> > path) {
    vector< vector<int> > res;
    for (auto p : path) {
        res.push_back( p );
    }
    return res;
}

int scalarProd(vector<int> a, vector<int> b) {
    double sc = 0;
    for (size_t c = 0; c < a.size(); c++) sc += a[c] * b[c];
    return sc;
}

bool isEqual(vector<int> a, vector<int> b) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

bool DFS (
            vector< vector< vector<int> > >& solutions,
            vector< vector<int> > cur_path,
            vector<int> cur_pos,
            vector<Node> nodes,
            vector<int> earthDir,
            int index
        )
{
    if ( dist(cur_pos, earthDir) <= 10e-6 ) {
        return true;
    }

    if ( index == nodes.size()) {
        return false;
    }

    for (int i = index; i < nodes.size(); i++) {
        Node node = nodes[i];
        vector< vector<int> > clonned_path = clonePath( cur_path );
        clonned_path.push_back(node.coord);
        if ( distOrigin(cur_pos) <= distOrigin(node.coord) && !isEqual(cur_pos, node.coord)) {
            if (DFS(solutions, clonned_path, node.coord, nodes, earthDir, index + 1)) {
                solutions.push_back( clonned_path );
            }
        }
    }
    return false;
}
double roundTo(double n, double q) {
    double p = pow(10, q);
    n = round(n * p);
    return n / p;
}

double truncate(double value) {
    return roundTo(value, 2);
}

std::vector<double> superman(
                             std::vector<int> earthCoordinates,
                             std::vector<std::vector<int>> fuelingStationsCoordinates
                             )
{

    vector<Node> nodes;
    for (auto p : fuelingStationsCoordinates) {
        // just doin' some projective stuff
        if ( scalarProd(p, earthCoordinates) > 0) {
            Node node(p, false);
            nodes.push_back( node );
        }
    }

    Node earth(earthCoordinates, true);
    nodes.push_back(earth);

    sort(nodes.begin(), nodes.end(), [&](Node a, Node b) {
         return distOrigin(a.coord) < distOrigin(b.coord);
    });

    std::vector< vector<int> > res;
    std::vector< vector< vector<int> > > solutions;
    vector< vector<int> > cur_path;

    // DFSearch
    DFS(solutions, cur_path, {0, 0, 0}, nodes, earthCoordinates, 0);

    vector<ResultItem> results;
    for (auto sol : solutions) {
        double cur_total_dist = 0;
        double cur_max_delta = -1;
        double cur_min_delta = INT_MAX;
        for (size_t i = 0; i < sol.size(); i++) {
            double delta = 0;
            if ( i == 0) {
                delta = distOrigin(sol[i]);
            } else {
                delta = dist(sol[i], sol[i-1]);
            }

            cur_max_delta = max(cur_max_delta, delta);
            cur_min_delta = min(cur_min_delta, delta);

            cur_total_dist += delta;
        }
        ResultItem item(
            truncate( cur_total_dist ),
            truncate( cur_max_delta ),
            truncate( cur_min_delta )
        );
        results.push_back( item );
    }

    /*
    results.clear();
    results.push_back( *(new ResultItem(3, 1, 1)) );
    results.push_back( *(new ResultItem(1, 1, 1)) );
    results.push_back( *(new ResultItem(2, 1, 2)) );
    results.push_back( *(new ResultItem(3, 1, 3)) );
    */
    sort(results.begin(), results.end(), [&](ResultItem a, ResultItem b) {
        if (a.max_delta == b.max_delta) {
            if (a.min_delta == b.min_delta) {
                return a.tot_dist < b.tot_dist;
            }
            return a.min_delta < b.min_delta;
        }
        return a.max_delta < b.max_delta;
    });

    // for (auto item : results) item.display();

    double min_delta = results[0].min_delta;
    double max_delta = results[0].max_delta;
    double min_dist = results[0].tot_dist;
    return vector<double>{min_dist, max_delta, min_delta};
}


int main() {
    vector<double> res = superman(
        {2, 2, 2},
        {
            {0,0,2},
            {0,2,2},
            {2,0,0}
        }
    );


/*
    vector<double> res = superman(
        {23, 21, 26},
        {{-20,3,-20},
         {2,21,11},
         {19,-1,-27},
         {-26,-25,6},
         {5,18,-26},
         {-18,27,-26}}
    );
*/

/*
    vector<double> res = superman(
        {-5, -5, -30},
        {{-10,5,-15},
         {10,3,-15},
         {0,10,-20}}
    );
*/
/*
    vector<double> res = superman(
        {-2, 2, -2},
        {
            {1,-1,1},
            {1,2,-2},
            {-2,2,-1}
        }
    );
*/
    for (auto r : res) {
        cout << r << endl;
    }
    return 0;
}
