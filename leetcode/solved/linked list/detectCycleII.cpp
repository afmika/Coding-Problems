/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> m;
        while ( true ) {
            if ( head == nullptr ) break;
            
            if ( !m[head] )
                m[head] = true;
            else
                return head;
            
            head = head->next;
        }
        return nullptr;
    }
};