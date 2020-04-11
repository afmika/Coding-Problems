
function ListNode(val) {
    this.val = val;
    this.next = null;
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
	let result = null, head = null;
	let r = 0;
	let longest = null;
	let count1 = 0, count2 = 0;
	while( l1 != null && l2 != null ) {
		let s = r + l1.val + l2.val;
		
		if(s >= 10) {
			s -= 10;
			r = 1;
		} else {
			r = 0;
		}
		
		if(result == null) {
			result = new ListNode( s );
			head = result;
		} else {
			result.next = new ListNode( s );
			result = result.next;
		}
		
		l1 = l1.next;
		l2 = l2.next;
		
		if(l1 != null)
			count1++;
		if(l2 != null)
			count2++;
	}
	
	if(count1 != count2) {
		let longest = count1 > count2 ? l1 : l2;
		while(longest != null) {
			let s = r + longest.val;
			console.log("s",s);
			if(s >= 10) {
				s -= 10;
				r = 1;
			} else {
				r = 0;
			}
			if(result == null) {
				result = new ListNode( s );
				head = result;
			} else {
				result.next = new ListNode( s );
				result = result.next;
			}
			longest = longest.next;
		}
	}
	if(r > 0)
		result.next = new ListNode(r);
	return head;
};

let l1 = new ListNode(2);
	l1.next = new ListNode(4);
	l1.next.next = new ListNode(6);
let l2 = new ListNode(5);
	l2.next = new ListNode(6);
	l2.next.next = new ListNode(4);
	l2.next.next.next = new ListNode(4);
	
let res = addTwoNumbers(l1, l2);
while(res != null) {
	console.log( res.val );
	res = res.next;
}	
