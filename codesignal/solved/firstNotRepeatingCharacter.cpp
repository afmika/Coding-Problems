char firstNotRepeatingCharacter(std::string s) {
    map<char, int> seen;
    int size = s.length();
    char unseen = -1;
    for (int i = 0; i < size; i++) {
        if (seen.find( s[i] ) == seen.end()) {
            seen[ s[i] ] = 0;
        } else {
            seen[ s[i] ]++;
        }
    }
    for (int i = 0; i < size; i++) {
        if ( seen.find( s[i] )-> second == 0) {
            return s[i];
        }
    } 
    return '_';
}
