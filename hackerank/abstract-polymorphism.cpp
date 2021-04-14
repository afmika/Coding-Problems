#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
    public:
        int count = 0;
        LRUCache (int cp) : Cache () {
            this->cp = cp;
            this->head = nullptr;
            this->tail = nullptr;
            this->mp = map<int, Node *>();
        }
        
        void set (int K, int V) override {
            Node *got = getNode(K);
            if (got != nullptr) {
                // cache hit
                // cerr << "hit\n";
                makeHead(got);
                got->value = V;
                return;
            }
            
            Node *node = new Node(nullptr, nullptr, K, V);
            this->mp[K] = node;
            if (head == nullptr && tail == nullptr) {
                head = node;
                tail = node;
            } else {
                // cache miss
                makeHead (node);                
            }
            if (count == cp) removeTail();
            count = min(cp, count + 1);
        }
        
        void makeHead (Node *node) {
            Node *next = node->next;
            Node *prev = node->prev;
            
            // chain broken links
            if (next != nullptr) next->prev = prev;
            if (prev != nullptr) prev->next = next;
            
            // make the current node as the current head
            Node *prec_head = this->head;
            prec_head->prev = node;
            node->next = prec_head;
            this->head = node;            
        }
        
        void removeTail () {
            if (count < 2) return;
            this->mp.erase(this->tail->key);
            
            // cerr << this->tail->value << "has been erased\n";

            Node *new_tail = this->tail->prev;
            this->tail = new_tail;
            this->tail->next = nullptr;
            
            // cerr << " remove tail " << "\n";
            this->count--;
        }
        
        Node *getNode (int K) {
            if (mp.find(K) == mp.end()) return nullptr;
            return mp[K];
        }
        
        int get (int K) override {
            if (getNode(K) == nullptr) return -1;
            return getNode(K)->value;
        }
        
        void showFromHead () {
			Node *t = this->head;
			while (t != nullptr) {
				cerr << t->key << " ";
				t = t->next;
			}
			cerr << "\n";
		}
};


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
      else if (command == "af") {
		l.showFromHead();
	  }
   }
   return 0;
}
