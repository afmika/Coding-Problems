/**
 * @author afmika
 */

#ifndef AFTOOLS_H_INCLUDED
#define AFTOOLS_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

namespace afTools {
    /**
     * @author afmika
     **/
    // TODO
    // REGEX REPLACE !

    float str_to_float(string str) {
        istringstream iss(str);
        float f = 0;
        iss >> f;
        return f;
    }

    double str_to_double(string str) {
        istringstream iss(str);
        double f = 0;
        iss >> f;
        return f;
    }

    int str_to_int(string str) {
        istringstream iss(str);
        int f = 0;
        iss >> f;
        return f;
    }

    template<typename Numeric>
    string number_to_str(Numeric n) {
        stringstream stream;
        stream << "" << n;
        return (string) stream.str();
    }

    // C++11, C++14 :)
    vector<string> match_regex(string rgx, string str) {
        vector<string> results;
        regex reg(rgx, regex_constants::ECMAScript | regex_constants::icase );
        sregex_iterator it = sregex_iterator(str.begin(), str.end(), reg);
        sregex_iterator end;

        while ( it != end ) {
            results.push_back( it->str() );
            ++it;
        }
        return results;
    }

    vector<string> split_regex(string rgx, string str) {
        vector<string> results;
        regex reg(rgx, regex_constants::ECMAScript | regex_constants::icase );
        // -1 => we tell the iterator to point stuff that precedes the match
        sregex_token_iterator it = sregex_token_iterator(str.begin(), str.end(), reg, -1);
        sregex_token_iterator end;

        while ( it != end ) {
            results.push_back( it->str() );
            ++it;
        }
        return results;
    }

    bool search_regex(string rgx, string str) {
        std::regex reg(rgx, regex_constants::ECMAScript | regex_constants::icase );
        return std::regex_search(str, reg);
    }
}

#endif // AFTOOLS_H_INCLUDED
