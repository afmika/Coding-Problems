class Solution {
public:
    map<char, char> m {
        {'{', '}'},
        {'(', ')'},
        {'[', ']'}
    };
    bool isValid(string s) {
        stack<char> st;
        int count = 0;
        for (char c : s ) {
            if (m.find(c) != m.end()) {
                // opening bracket
                st.push( c );
            } else {
                // closing bracket
                // Only appens when the string starts with a closing bracket
                if ( st.empty() )
                    return false;
                if ( m[ st.top() ] == c ) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
		// true if empty
        return st.empty();
    }
};