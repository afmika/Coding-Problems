/*
211. Design Add and Search Words Data Structure
Medium

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

    WordDictionary() Initializes the object.
    void addWord(word) Adds word to the data structure, it can be matched later.
    bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

*/
class WordDictionary {
public:
    // size -> {first char -> [w1, ..., wN]}
    unordered_map<int, unordered_map<char, vector<string>> > words;
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int key = word.size();
        char first_char = word[0];
        if ( words.find(key) == words.end() ) {
            words[key] = * ( new unordered_map<char, vector<string>>() );
            words[key][first_char] = * (new vector<string>());
        }
        
        words[key][first_char].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int key = word.size();
        char first_char = word[0];
        
        if ( words.find(key) == words.end() )
            return false;
        
        regex pattern(word);
        
        if ( first_char != '.' ) {
            if ( words[key].find(first_char) == words[key].end() )
                return false;      
            for (string w : words[key][first_char]) {
                if (regex_match(w, pattern))
                    return true;            
            }              
        } else {
            for (auto v : words[key]) {
                for (string w : v.second) {
                    if (regex_match(w, pattern))
                        return true;            
                }
            }  
        }
 
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */