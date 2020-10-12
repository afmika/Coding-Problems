/*
Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at A[i] and A[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.

Example 2:

Input: A = "ab", B = "ab"
Output: false
Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.

*/
class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        if ( A.size() != B.size() || A.compare("") == 0)
            return false;
        
        map<char, int> char_count;
        map<char, int> char_map;
        
        for (char a : A) {
            char_count[a]++;
            char_map[a]++;
        }
        
        for (char b : B) {
            if (char_count.find(b) == char_count.end()) 
                return false;
            char_count[b]--;
        }   
        
        for (auto item : char_count)
            if (item.second < 0)
                return false;
        
        int size = A.size();
        int offset = -1;
        int candidates_count = 0;
        for (int i = 0; i < size; i++ ) {
            if ( A[i] != B[i] ) {
                candidates_count = size - i;
                offset = i;
                break;
            }
        }
        
        if ( offset < 0 && A.compare(B) != 0 ) return true;
        for (int i = 0; i < candidates_count; i++) {
            int u = offset;
            int v = offset + i + 1;
            swap(B[u], B[v]);
            if ( A.compare(B) == 0 ) 
                return true;
            swap(B[u], B[v]);
        }
        
        int count = 0;
        for (auto c : char_map)
            count += (c.second > 1 ? 1 : 0);
		
        return count > 0 && offset < 0;
    }
};