#include <iostream>

using namespace std;
typedef struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
} ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode * result = NULL;
	ListNode * head = NULL;
	int r = 0;
	size_t count1 = 0, count2 = 0;
	while( l1 != NULL && l2 != NULL ) {
		int s = r + l1->val + l2->val;
		
		if(s >= 10) {
			s -= 10;
			r = 1;
		} else {
			r = 0;
		}
		
		if(result == NULL) {
			result = new ListNode( s );
			head = result;
		} else {
			result->next = new ListNode( s );
			result = result->next;
		}
		
		l1 = l1->next;
		l2 = l2->next;
		
		if(l1 != NULL)
			count1++;
		if(l2 != NULL)
			count2++;
	}
	
	if(count1 != count2) {
		ListNode * longest = count1 > count2 ? l1 : l2;
		while(longest != NULL) {
			int s = r + longest->val;
			if(s >= 10) {
				s -= 10;
				r = 1;
			} else {
				r = 0;
			}
			if(result == NULL) {
				result = new ListNode( s );
				head = result;
			} else {
				result->next = new ListNode( s );
				result = result->next;
			}
			longest = longest->next;
		}
	}
	if(r > 0)
		result->next = new ListNode(r);
	return head;    
}

int main() {
	ListNode * l1 = new ListNode(8);
	l1->next = new ListNode(3);
	l1->next->next = new ListNode(8);
	
	ListNode * res = addTwoNumbers(l1, l1);
	while(res != NULL) {
		cout << res->val << " ";
		res= res->next;
	}
	return 0;
}