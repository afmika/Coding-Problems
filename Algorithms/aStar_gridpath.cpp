/**
 * @author afmika
 */

#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> Graph;

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
    if (y < 0 || x < 0 || y >= graph.size() || x >= graph[0].size())
        return false;
    return graph[y][x] == 0;    
}

vector<Node *> neighborsOf (Node *a, Graph &graph) {
    vector<vector<int>> dir = {
        {-1, 0}, {1, 0}, {0, 1}, {0, -1}, // horiz / vert
        {-1, -1}, {1, 1}, {1, -1}, {-1, 1} // diag
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

string backtrackPath (Node *end_node) {
    string path = "";
    bool started = true;
    while (end_node != nullptr) {
        path = "[" + to_string(end_node->y) + ", " + to_string(end_node->x) + "]" 
                + (started ? "" : "=>") + path;
        started = false;
        end_node = end_node->parent;
    }
    return path;
}

void aStar (Graph graph, vector<int> _start, vector<int> _end) {
    vector<Node *> closedList;
    vector<Node *> openList;
    Node *start = makeNode (_start);
    Node *end = makeNode (_end);
    openList.push_back(start);

    while (!openList.empty()) {
        Node *curr = openList[0];
        openList.erase(openList.begin()); // pop_front

        if (nodeEqual(curr, end)) {
            cout << backtrackPath(curr);
            return;
        }

        vector<Node *> neighb = neighborsOf (curr, graph);
        for (auto nei : neighb) {
            bool notInClosedList = !findNodeInList(nei, closedList);
            if (notInClosedList) {
                nei->cost = curr->cost + 1; // 1 dist 
                nei->heur = nei->cost +  heuristic (nei, end); // dist^2
                // --- useful when we want to backtrack the answer
                nei->parent = curr;
                // ---- 
                openList.push_back(nei);
            }
        }
        closedList.push_back(curr);
    }
    cout << "Impossible path";
}

int main () {
    Graph graph = { 
        { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 1, 0, 1, 0 },
        { 1, 1, 0, 1, 0, 1, 1, 1, 1, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
        { 0, 1, 0, 0, 0, 0, 1, 0, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 0 },
        { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 1, 0, 1, 1, 0 }
    };
    aStar (graph, {8, 0}, {0, 0});
    return 0;
}