#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> c {
    {'D', 0},
    {'W', 1},
    {'L', -1}
};

unordered_map<int, string> text {
    {0, "DRAWS"},
    {1, "WINS"},
    {-1, "LOSES"}
};

struct Node {
    Node *left, *right;
    int val;
    Node (int val) { this->val = val; }
};

bool expOdd (double s) {
    return (int) (log(s) / log(2)) % 2 != 0;
}

int minimax(bool do_max, int u, int v) {
    return do_max ? max(u, v) : min (u, v);
}

int main() {
    string input;
    cin >> input;
    vector<Node *> gen;
    int i = 0;
    while (i < (int) input.size()) {
        int val = c[input[i++]];
        gen.push_back(new Node(val));
    }
    vector<Node *> last_gen = gen;
    
    bool do_max = expOdd((double) gen.size());    
    while (gen.size() > 1) {
        vector<Node *> new_g;
        int i = 0;
        while (i < (int) gen.size()) {
            Node *a = gen[i++];
            Node *b = gen[i++];
            int u = a->val, v = b->val;
            Node *node = new Node(minimax(do_max, u, v));
            node->left = a;
            node->right = b;
            new_g.push_back(node);
            cerr << a->val << " " << b->val << " ";
        }
        cerr << "\n";
        do_max = !do_max;        
        gen = new_g;
    }
    do_max = !do_max;
    cerr << gen.size() << " and val is " << gen[0]->val << "\n";
    Node *root = gen[0];
    
    cout << text[root->val];
    cerr << "yay";
    return 0;
}
