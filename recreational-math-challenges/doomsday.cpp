#include <bits/stdc++.h>

using namespace std;

// https://www.timeanddate.com/date/doomsday-weekday.html
void doomsday (int full_year) {
    string days [7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    
    unordered_map<int, int> anchor = {
        // 1800 to (1800 + 100 - 1)
        {1800, 4},
        {1900, 3},
        {2000, 1},
        {2100, 6}
    };
    
    int yy = atoi(to_string(full_year).substr(2, 2).c_str());
    
    // yy = step1 * 12 + step2
    // step2 = yy - step1 * 12
    int step1 = yy / 12;
    int step2 = yy % 12;
    int step3 = step2 / 4;
    
    // step 4
    // What is the century's anchor day?
    int anchor_day = 0;
    for (auto v : anchor) {
        if (full_year >= v.first && full_year <= (v.first + 100 - 1) ) {
            anchor_day = v.second;
            break;
        }
    }
    cout << "Step 1 : " << step1 << "\n";
    cout << "Step 2 : " << step2 << "\n";
    cout << "Step 3 : " << step3 << "\n";
    cout << "Step 4 : " << anchor_day << "\n";
    int step5 = step1 + step2 + step3 + anchor_day;
    // Note "sunday" is 0 !!!!!
    cout << "Result " << days[step5 % 7] << "\n\n";
}

int main() {
    doomsday (1978);
    return 0;
}
