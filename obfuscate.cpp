#include <bits/stdc++.h>

using namespace std;

namespace af {
    typedef long long t_container; // change this
    
    vector<t_container> compileAsList (string in) {
        assert (in.size() > 0);
        assert (sizeof(t_container) >= 1);
        vector<pair<char, int>> ct;
        char curr = in [0]; int count = 1;
        for (int i = 1, s = (int) in.size(); i < (1 + s); i++) {
            if (i == s || in[i] != curr) {
                ct.push_back ({curr, count});
                count = 0;
            }
            curr = in[i];
            count++;
        }
        t_container temp_container = 0;
        int i = 0, places = sizeof(t_container) / sizeof(int);
        vector<t_container> list;
        for (auto &p : ct) {
            // uint64 ==> uint32 | (uint32 << 32)
            int offset = 8 * sizeof(int) * i;
            // p.second should be less than 24 bits  
            t_container value  = (t_container) ((int) p.first) | (p.second << 8);
            temp_container = temp_container | (value << offset);
            places--;
            i++;
            if (places == 0) {
                places = sizeof(t_container) / sizeof(int);
                list.push_back (temp_container);
                temp_container = 0;
                i = 0;
            }
        }
        if (places > 0)
            list.push_back (temp_container);
        return list;
    }
    
    string decompileAsString (vector<t_container> list) {
        assert (sizeof(t_container) >= 1);
        string res = "";
        int places = sizeof(t_container) / sizeof(int);
        for (auto value : list) {
            for (int i = 0; i < places; i++) {
               int offset = 8 * sizeof(int) * i;
               int v = value >> offset;
               char c = v & 0xFF;
               int count = (v >> 8);
               while (count--) res += c;
            }
        }
        return res;
    }
};

string fetchInputs () {
    string res = "";
    string line;
    while (std::getline(std::cin, line)) {
        res += line;
    }
    return res;
}


int main() {
    string str = "##########################::::::... ....:::::###########";
    vector<af::t_container> list = af::compileAsList (str);
    string res = af::decompileAsString (list);
    cout << str << "\n";
    cout << res << "\n";
    cout << "\n";
    
    int c = 1;
    for (af::t_container l : list) {
        printf("0x%llx, ", l);
        if (c % 6 == 0) printf("\n");
        c++;
    }
    cout << "\n";
    
    
    // tests
    vector<af::t_container> temp = {
        0x63a00001a23, 0x1200000032e, 0x53a0000042e, 0xb23,
    };
    cout << af::decompileAsString (temp);
    return 0;
}
