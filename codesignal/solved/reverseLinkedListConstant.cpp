/*
Note: Your solution should have O(l.length) time complexity and O(1) space complexity, since this is what you will be asked to accomplish in an interview.

Given a singly linked list, reverse and return it.

Example

For l = [1, 2, 3, 4, 5], the output should be
reverseLinkedList(l) = [5, 4, 3, 2, 1].

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] linkedlist.integer l

    A singly linked list of integers.

    Guaranteed constraints:
    0 ≤ l.length ≤ 105,
    -109 ≤ l.value ≤ 109.

    [output] linkedlist.integer
        Reversed l.
*/
// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * reverseLinkedList(ListNode<int> * l) {
    ListNode<int> * res = NULL;
    while ( l != NULL ) {
        ListNode<int> * next = l->next;
        if (res == NULL) {
            res = l;
            res->next = NULL;
        } else {
            ListNode<int>* before = res;
            res = l;
            res->next = before;
        }
        l = next;
    }
    return res;
}