#include <iostream>
#include <vector>

using namespace std;

string pad (string s) { return s.size() == 1 ? "0" + s : s; }
/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    int q = s.size() - 2;
    bool isAM = s[q] == 'A';
    string ss = s.substr(0, q);
    
	int val = (int) ((ss[0] - '0') * 10 + (ss[1] - '0'));
    
	int offset = isAM ? 
			  (val >= 12 ? -12 : 0) 
			: (val < 12 ? 12 : 0);
			
    return pad(to_string(val + offset)) + ":" + ss.substr(3);
}

int main () {
	vector<string> tests = {
		"08:04:00PM",
		"03:04:00PM",
		"08:04:00AM",
		"08:04:00AM",
		"07:04:00PM"
	};
	for (string t : tests) cout << timeConversion (t) << "\n";
	return 0;
}