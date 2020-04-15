/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

*/
 function ListNode(val) {
      this.val = val;
      this.next = null;
 }
 
 function display(list) {
	 let a = [];
	 while(list != null) {
		 a.push( list.val );
		 list = list.next;
	 }
	 console.log( a );
 }
 function arrayToLinkedList( arr ) {
	 let list = new ListNode(null);
	 let head = list;
	 for(let i = 0; i < arr.length; i++) {
		 list.val = arr[i];
		 if(i + 1 != arr.length )
			list.next = new ListNode(null);
		 list = list.next;
	 }
	 return head;
 }
 
 
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeKLists = function( lists ) {
	
	let lead = null; // lead
	let last = null; // last
	
	// which list will be in the lead ?
	let t1 = l1, t2 = l2;
	let min = +Infinity;
	let total_size = 0;
	while( t1 != null || t2 != null) {		
		if(t1 != null) {
			if( t1.val < min ) {
				lead = l1;
				last = l2;
				min = t1.val;
			}
			t1 = t1.next;
			total_size++;
		}
		if(t2 != null) {
			if( t2.val < min ) {
				lead = l2;
				last = l1;
				min = t2.val;
			}
			t2 = t2.next;
			total_size++;
		}
	}
    
	// connecting both
	let ptr = lead;
    while(ptr.next != null)
        ptr = ptr.next;
    ptr.next = last;
    
    if(total_size <= 2)
        return lead;
	
    let head = lead;
	ptr = head;
	while( head != null ) {
		let a = head;
		let b = head.next;
		if(b != null) {
			if(a.val  > b.val ) {
				let temp = a.val;
				a.val = b.val;
				b.val = temp;
				head = ptr;
				continue;
			}			
		}
		head = head.next;
	}
	return lead;
};


let l1 = arrayToLinkedList( [2, 2, 4, 6, 8, 9] );
let l2 = arrayToLinkedList( [3, 5, 7] );
let l3 = arrayToLinkedList( [3, 5, 7] );

display( mergeKLists( [ l1, l2, l3 ])  )