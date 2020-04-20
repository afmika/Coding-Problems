/*
Problem

There are N houses for sale. The i-th house costs Ai dollars to buy. You have a budget of B dollars to spend.

What is the maximum number of houses you can buy?
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a single line containing the two integers N and B. The second line contains N integers. The i-th integer is Ai, the cost of the i-th house.
Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum number of houses you can buy.
Limits

Time limit: 15 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ B ≤ 105.
1 ≤ Ai ≤ 1000, for all i.
Test set 1

1 ≤ N ≤ 100.
Test set 2

1 ≤ N ≤ 105.
Sample

Input
  	
Output
 

3
4 100
20 90 40 90

4 50
30 30 10 10

3 300
999 999 999


Case #1: 2
Case #2: 3
Case #3: 0  
*/

#include <iostream>
#include <vector>

using namespace std;
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = arr[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(arr[i] < pivotValue) {
            i++;
        }
        while(arr[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<int> &arr, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(arr, left, right);
        quicksort(arr, left, pivotIndex - 1);
        quicksort(arr, pivotIndex, right);
    }
}

void sort(vector<int> &arr) {
	quicksort(arr, 0, arr.size() - 1);
}

int main() {
	int n_tests, cur_money;
	cin >> n_tests;
	vector< vector<int> > samples( n_tests );
	vector<int> moneys( n_tests );
	
	for(int i = 0; i < n_tests; i++) {
		int n_houses, money;
		cin >> n_houses >> money;
		moneys[ i ] = money;
		vector<int> houses( n_houses );
		int k = 0;
		while( k < n_houses ) {
			cin >> houses[k];
			k++;
		}
		
		sort( houses );
		samples[i] = houses;
	}	
	
	for(int i = 0; i < n_tests; i++) {
		// cout << "Index #" << i + 1 << endl;
		// cout << "Money " << moneys[i] << " N_houses " << samples[i].size() << endl;
		/*
		for(int k = 0; k < samples[i].size(); k++) {
			cout << samples[i][k] << " ";
		}
		*/
		int cur_count = 0, k = 0;
		int cur_size = samples[i].size();
		while ( k < cur_size ) {
			int cur_money = moneys[ i ];
			cur_money -= samples[ i ][ k ];
			if ( cur_money >= 0) {				
				moneys[ i ] = cur_money;
				cur_count++;
			} else {
				break;
			}
			k++;
		}
		cout << "Case #" << i + 1 << ": " << cur_count << endl;
	}	
	
	return 0;
}