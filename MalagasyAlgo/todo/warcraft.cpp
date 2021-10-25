/**
 * @author afmika
 */

#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<char>> Graph;

struct Node {
    int y, x; // pos
    double cost, heur; // cost and heuristic
    Node *parent; // backtrack path
    Node (int y, int x) {
        this->y = y, this->x = x;
        this->cost = 0, this->heur = 0;
        this->parent = nullptr;
    }
};

Node * makeNode (vector<int> a) {
    return new Node (a[0], a[1]);
}

int canGo (int y, int x, Graph &graph) {
    if (y < 0 || x < 0 || y >= (int) graph.size() || x >= (int) graph[0].size())
        return false;
    return graph[y][x] == '-';    
}

vector<Node *> neighborsOf (Node *a, Graph &graph) {
    vector<vector<int>> dir = {
        {-1, 0}, {1, 0}, {0, 1}, {0, -1}, // horiz / vert
    };
    vector<Node *> list;
    for (auto d : dir) {
        int dy = d[0], dx = d[1];
        Node *new_p = makeNode({a->y + dy, a->x + dx});
        if (canGo(new_p->y, new_p->x, graph))
            list.push_back(new_p);
    }
    return list;
}

int distSq (Node *a, Node *b) {
    return pow(a->x - b->x, 2) + pow(a->y - b->y, 2);
}

int heuristic (Node *a, Node *b) {
    return distSq (a, b);
}

bool nodeEqual (Node *a, Node *b) {
    return a->x == b->x && a->y == b->y;
}

bool findNodeInList (Node *a, vector<Node *> &list) {
    for (auto it : list)
        if (nodeEqual(it, a))
            return true;
    return false;
}

Node *backtrackPath (Node *end_node) {
    Node *prec = nullptr;
    while (end_node->parent != nullptr) {
        prec = end_node;
        end_node = end_node->parent;
    }
    return prec;
}

Node *aStar (Graph graph, vector<int> _start, vector<int> _end) {
    vector<Node *> closedList;
    vector<Node *> openList;
    Node *start = makeNode (_start);
    Node *end = makeNode (_end);
    openList.push_back(start);

    while (!openList.empty()) {
        Node *curr = openList[0];
        openList.erase(openList.begin()); // pop_front

        if (nodeEqual(curr, end)) {
            return backtrackPath(curr);
        }

        vector<Node *> neighb = neighborsOf (curr, graph);
        for (auto nei : neighb) {
            bool notInClosedList = !findNodeInList(nei, closedList);
            if (notInClosedList) {
                nei->cost = curr->cost + 1;
                nei->heur = nei->cost +  heuristic (nei, end);
                nei->parent = curr;
                openList.push_back(nei);
            }
        }
        closedList.push_back(curr);
    }
    return nullptr;
}

int main () {
    int nrow, ncol;
    cin >> nrow >> ncol;
    Graph graph(nrow);
    for (int y = 0; y < nrow; y++) {
        graph[y] = vector<char>(ncol);
        for (int x = 0; x < ncol; x++) {
            cin >> graph[y][x];
        }
    }
    int agy, agx;
    cin >> agy >> agx;
    int npos;
    cin >> npos;
    int k = 0;
    vector<vector<int>> ppos;
    while (k < npos) {
        int y, x;
        cin >> y >> x;
        ppos.push_back({y, x});
        cerr << y << x << "\n";
        k++;
    }
    
    for (auto player : ppos) {
        int py = player[0], px = player[1];
        int dx = abs(agy - py), dy = abs(agx - px);
        bool hnear = (dx == 1 && dy == 0);
        bool vnear = (dx == 0 && dy == 0);
        if (hnear || vnear ) {
            cout << "stay at " << agy << " " << agx << "\n";
            continue;
        }
        Node * out = aStar (graph, {agy, agx}, player);
        if (out->y == py && out->x == px) {
            cout << "stay at " << agy << " " << agx << "\n";
            continue;
        }
        cout << "move to " << out->y << " " << out->x << "\n";
        agy = out->y;
        agx = out->x;
    }
    
    return 0;
}
