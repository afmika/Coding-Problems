/*
 Design a data structure that supports 
 all following operations in average O(1) time.
	
    avg O(1) : insert(val): Inserts an item val to the set if not already present.
    avg O(1) : remove(val): Removes an item val from the set if present.
    avg O(1) : getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

 * */

#include <bits/stdc++.h>
using namespace std;
    
class RandomizedSet {
public:
    typedef struct Item {
        int val;
        bool state;
    } Item;
        
    map<int, Item> m_set;
    map<int, int> pos;
    
    int size = 0;
    int acc_size_so_far = 0;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        /* initialize random seed: */
		srand (time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element.*/
    bool insert(int val) {
        if ( m_set.find(val) == m_set.end() ) {
			Item st; st.val = val; st.state = true;
            m_set[val] = st;
            pos[size] = val;
            size++;
            acc_size_so_far++;
            return true;
        }
        if ( ! m_set[val].state ) {
			size++;
			m_set[val].state = true;
			return true;
		}
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if ( m_set.find(val) == m_set.end() ) {
            return false;
        }
        if ( m_set[val].state ) {
			size = max(0, size - 1);
			m_set[val].state = false;
			return true;
		}
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if ( size != 0 ) {
			
            if ( size == 1 ) {
				for ( int i = 0; i < acc_size_so_far; i++ ) {
					int v = pos[i];
					if ( m_set[v].state ) {
						return v;
					}
				}
			}
            
			// acc_size_so_far represents the total number of deleted + inserted items
            int rnd = rand() % acc_size_so_far;  
            int cur_val = pos[rnd];
            if ( m_set[cur_val].state ) {
                return cur_val;
            } else {
				// Fails, try another
                return getRandom();
            }
        }
        // we can return whatever we want
		// if the set is empty
        return 0;
    }
};


int main() {
	
	RandomizedSet m;
	cout << m.insert(1) << endl;
	cout << m.insert(4) << endl;
	cout << m.insert(2) << endl;
	cout << m.remove(2) << endl;
	cout << m.insert(2) << endl;
	cout << m.insert(5) << endl;
	
	for (auto i : m.m_set) {
		cout << i.first << " : " << i.second.state << endl;
	}
	cout << "\n";
	
	map<int, int> count;
	for (int i = 0; i < 1000; i++) {
		int val = m.getRandom();
		if (count.find(val) == count.end() ) count[m.getRandom()] = 1;
		else count[m.getRandom()]++;
	}
	for (auto p : count) {
		cout << p.first << " : " << p.second << " times"<< "\n";
	}
}
