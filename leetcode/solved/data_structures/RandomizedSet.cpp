/*
 Design a data structure that supports 
 all following operations in average O(1) time.
	
    avg O(1) : insert(val): Inserts an item val to the set if not already present.
    avg O(1) : remove(val): Removes an item val from the set if present.
    avg O(1) : getRandom: Returns a random element from current set of elements. 
	Each element must have the same probability of being returned.

 * */

#include <bits/stdc++.h>
using namespace std;
    

class Item {
public:
	int val;
	bool isAlive;
	Item() {}
	Item(int val, bool isAlive) { 
		this->val = val;
		this->isAlive = isAlive;
	}
};

class RandomizedSet {
public:	
    map<int, Item> m_set;
    map<int, int> pos;
    
    int size = 0; // virtual size
    int real_map_size = 0; // total size (removed + active)
    
    RandomizedSet() {
        /* initializes the random seed: */
		srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element.*/
    bool insert(int val) {
        if ( m_set.find(val) == m_set.end() ) {
			Item it(val, true);
            m_set[val] = it;
            pos[size] = val;
            size++;
            real_map_size++;
            return true;
        }
        if ( ! m_set[val].isAlive ) {
			size++;
			m_set[val].isAlive = true;
			return true;
		}
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if ( m_set.find(val) == m_set.end() ) {
            return false;
        }
        if ( m_set[val].isAlive ) {
			size = max(0, size - 1);
			m_set[val].isAlive = false;
			return true;
		}
        return false;
    }
    
    /** Gets a random element from the set. */
    int getRandom() {
        if ( size != 0 ) {
			
            if ( size == 1 ) {
				// single item left
				for ( int i = 0; i < real_map_size; i++ ) {
					int v = pos[i];
					if ( m_set[v].isAlive ) {
						// found it !
						return v;
					}
				}
			}
            
            // pick a random position
            int rnd = rand() % real_map_size;  
            int cur_val = pos[rnd];
            
            if ( m_set[cur_val].isAlive ) {
                return cur_val;
            } else {
				// Fail, try another
                return getRandom();
            }
        }
		// the set is empty
        return 0;
    }
};


// Tests

void runTests(vector<pair<string, int>> tests) {
	RandomizedSet m;
	for (auto test : tests) {
		string type = test.first;
		int value   = test.second;
		cout << type << " " << value;
		bool output = false;
		if (type.compare("insert") == 0) {
			output = m.insert(value);
		} else if (type.compare("remove") == 0) {
			output = m.remove(value);
		} 
		
		cout << ", Output " << output << "\n";
	}
	
	cout << "\nItems : " << "\n";
	for (auto i : m.m_set) {
		cout << i.first << " : " << (!i.second.isAlive ? "removed" : "active") << endl;
	}
	cout << "\n";
	
	int n_calls = 1200;
	cout << "getRandom : Number of calls " << n_calls <<  "\n";
	map<int, int> count;
	for (int i = 0; i < n_calls; i++) {
		int val = m.getRandom();
		if (count.find(val) == count.end() ) count[m.getRandom()] = 1;
		else count[m.getRandom()]++;
	}
	for (auto p : count) {
		cout << p.first << " : called " << p.second << " times"<< "\n";
	}
}

int main() {
	vector<pair<string, int>> tests = {
		{"insert", 1},
		{"insert", 4},
		{"insert", 2},
		{"remove", 2},
		{"remove", 2},
		{"insert", 2},
		{"insert", 3},
		{"remove", 4}
	};
	runTests( tests );
	return 0;
}
