/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if ( head == nullptr || k == 0 ) return head;
        ListNode* temp = head;
        ListNode* prev_tail = head;
        ListNode* init_head = head;
        int s = 0;
        while ( temp != nullptr ) {
            prev_tail = temp;
            temp = temp->next;
            s++;
        }
        
        if ( s == 1 || k == s) 
            return head;
        
        if ( k > s )
            return rotateRight(head, k % s);
        
        int q = s - k + 1;
        ListNode* cur_tail = head;
        while ( --q ) {
            cur_tail = head;
            head = head->next;
        }
        cur_tail->next = nullptr;
        prev_tail->next = init_head;
        
        return head;
    }
};