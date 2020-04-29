/**
 * Definition for singly-linked list.
 */
 function ListNode(value) {
      this.value = value;
      this.next = null;
 }
 
 function display(list) {
	 let a = [];
	 while(list != null) {
		 a.push( list.value );
		 list = list.next;
	 }
	 console.log( a );
 }
 function arrayToLinkedList( arr ) {
	 let list = new ListNode(null);
	 let head = list;
	 for(let i = 0; i < arr.length; i++) {
		 list.value = arr[i];
		 if(i + 1 != arr.length )
			list.next = new ListNode(null);
		 list = list.next;
	 }
	 return head;
 }
 
/**
 * Definition for singly-linked list.
 * function ListNode(value) {
 *     this.value = value;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLinkedLists = function(l1, l2) {
	if(l1 == null && l2 == null)
		return null;
	
	let lead = null; // lead
	let last = null; // last
	
	// which list will be in the lead ?
	let t1 = l1, t2 = l2;
	let min = +Infinity;
	let total_size = 0;
	while( t1 != null || t2 != null) {		
		if(t1 != null) {
			if( t1.value < min ) {
				lead = l1;
				last = l2;
				min = t1.value;
			}
			t1 = t1.next;
			total_size++;
		}
		if(t2 != null) {
			if( t2.value < min ) {
				lead = l2;
				last = l1;
				min = t2.value;
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
			if(a.value  > b.value ) {
				let temp = a.value;
				a.value = b.value;
				b.value = temp;
				head = ptr;
				continue;
			}			
		}
		head = head.next;
	}
	return lead;
};
let l1 = arrayToLinkedList( [1, 1, 2, 4] );
let l2 = arrayToLinkedList( [0, 3, 5] );
display( mergeTwoLinkedLists(l1, l2) );
