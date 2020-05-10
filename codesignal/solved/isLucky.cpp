/*
Ticket numbers usually consist of an even number of digits. A ticket number is considered lucky if the sum of the first half of the digits is equal to the sum of the second half.

Given a ticket number n, determine if it's lucky or not.
*/
bool isLucky(int n) {
    string tmp = to_string( n );
    int l = 0, r = 0;
    for (int i = 0; i < tmp.size() / 2; i++) {
        int j = tmp.size() - 1 - i;
        l += tmp[i] - '0';
        r += tmp[j] - '0';
    }
    return l == r;
}