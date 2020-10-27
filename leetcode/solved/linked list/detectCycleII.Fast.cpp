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
        while ( true ) {
            if ( head == nullptr ) break;
            if ( head->val == INT_MAX )
                return head;
            else
                head->val = INT_MAX;
            head = head->next;
        }
        return nullptr;
    }
};