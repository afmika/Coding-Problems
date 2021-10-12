long repeatedString(string s, long n) {
    int i = 0, c = 0, len = s.size();
    /*
    while (n--) {
        if (s[i++] == 'a') c++;
        i %= len;
    }
    return c;*/
    long p = n / len;
    long as = 0;
    for (int i = 0; i < len; i++)
        if (s[i] == 'a') as++;
    long total = as * p;
    // cerr << p << "yoho";
    for (int i = 0; i < (n%len); i++)
        if (s[i] == 'a') total++;
    return total;
}