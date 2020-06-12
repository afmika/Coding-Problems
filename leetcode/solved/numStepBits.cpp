/*
 Given a number s in their binary representation. Return the number of steps to reduce it to 1 under the following rules:

    If the current number is even, you have to divide it by 2.

    If the current number is odd, you have to add 1 to it.

It's guaranteed that you can always reach to one for all testcases.

 

Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  

Example 2:

Input: s = "10"
Output: 1
Explanation: "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  

Example 3:

Input: s = "1"
Output: 0

 

Constraints:

    1 <= s.length <= 500
    s consists of characters '0' or '1'
    s[0] == '1'


 */
#include <bits/stdc++.h>
using namespace std;
bool isOdd(string n) {
	return n[n.size() - 1] == '1';
}

bool isOne(string n) {
	return n.size() == 1 && isOdd(n);
}

string addOne(string s) {
	string res = "";
	int i = s.size() - 1;
	bool reminder = true; // +1
	while ( i >= 0 ) {
		char c = s[i];
		if ( reminder ) {
			char cur = c == '0' ? '1' : '0';
			if ( c == '0' ) {
				reminder = false;
			}
			res = cur + res; 
		} else {
			res = c + res;
		}
		i--;
	}
	if ( reminder )
		return '1' + res;
	return res;
}

string divideByTwo(string s) {
	return s.substr(0, s.size() - 1);
}

int start_count(string n, int step_count) {
	if ( isOne(n) ) return step_count;
	if ( isOdd(n) ) {
		step_count++;
		n = addOne(n);
	}        
	n = divideByTwo(n);
	return start_count(n, step_count + 1);
}

int numSteps(string s) {
	return start_count(s, 0);
}

int main() {
	//cout << addOne("11") << endl;
	//cout << addOne("1011") << endl;
	//cout << addOne("10110001") << endl;
	//cout << addOne("10110011") << endl;
	//cout << addOne("10110010") << endl;

	// cout << isOdd("101") << isOdd("10") << endl;
	//cout << addOne("11") << " " << addOne("1010") << endl;
	//cout << divideByTwo("10") << " " << divideByTwo("1010") << endl;
	//cout << isOne("1") << " " << isOne("10") << endl;
	cout << numSteps("1000") << endl;
	cout << numSteps("10010001111000110110001") << endl;
	return 0;
}
