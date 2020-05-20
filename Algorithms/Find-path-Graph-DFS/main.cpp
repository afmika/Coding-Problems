/**
Simple test
Given two nodes

Returns all possible paths that connects them
**/

#include <bits/stdc++.h>

using namespace std;

typedef struct OrientedGraph {
    map< string, vector< pair<string, float> > > connections;

    void connect(string node_a, string node_b, float weight) {
        connections[ node_a ].push_back( pair<string, float>(node_b, weight) );
    }
    float get( string node_a, string node_b ) {
        if ( connections.find(node_a) != connections.end() ) {
            for ( auto node : connections[ node_a ] ) {
                if ( node.first.compare( node_b ) == 0 ) {
                    return node.second;
                }
            }
        }
        return -1;
    }

    void displayStructure() {
        for ( auto c : this->connections) {
            cout << c.first << " : "<< c.second.size() << " links" << endl;
            for ( auto p : c.second ){
                cout << c.first << " --> " << p.first;
                cout << " : " << p.second << endl;
            }
        }
    }
} OrientedGraph;


bool check (
              set< pair<string, float> >& result,
              map< string, short >& traversed,
              string temp,
              string dep,
              string a,
              string b,
              OrientedGraph& graph,
              int dist,
              bool first
          ) {

    if ( a.compare(b) == 0 ) {
        result.insert( {temp, dist} );
        traversed.insert( {temp, 1} );
    }

    if ( a.compare(dep) == 0 && ! first) {
        // loop (ex : A B C A )
        return false;
    }

    if ( graph.connections.find(a) == graph.connections.end() ) {
        return false;
    }

    for ( auto couple : graph.connections[ a ]) {
        string new_temp = temp + couple.first;
        if ( traversed.find( new_temp ) == traversed.end()  ) {
            float new_dist = dist + couple.second;
            if ( check(result, traversed, new_temp, dep, couple.first, b, graph, new_dist, false) ) {
                return true;
            }
        }
    }

    return false;
}


set< pair<string, float> > findPossiblePathFrom(string a, string b, OrientedGraph& graph) {
    set< pair<string, float> > result;
    map< string, short > traversed;
    if ( graph.connections.find(a) == graph.connections.end() ) {
        return result;
    }

    string str = a;
    check( result, traversed, str, a, a, b, graph, 0, true);

    return result;
}

pair<string, float> findShortestPathInside(set< pair<string, float> > paths) {
    float min = INT_MAX;
    pair<string, float> res;
    for (auto p : paths) {
        if ( min > p.second ) {
            min = p.second;
            res = p;
        }
    }
    return res;
}

int main() {
    OrientedGraph graph;
    graph.connect("A", "D", 40);
    graph.connect("A", "B", 4);
    graph.connect("A", "C", 3);

    graph.connect("B", "C", 3);
    graph.connect("B", "C", 4);

    graph.connect("C", "D", 5);
    graph.connect("C", "E", 3);
    graph.connect("C", "F", 3);

    graph.connect("E", "D", 1);

    graph.connect("F", "E", 1);


    set< pair<string, float> > paths = findPossiblePathFrom("A", "D", graph);
    for ( auto s : paths) {
        cout << "Path => " << s.first;
        cout << " Dist " << s.second << endl;
    }

    pair<string, float> shortest = findShortestPathInside( paths );
    cout << "Shortest path " << shortest.first << ", dist = " << shortest.second << endl;

    return 0;
}
