string numify(int n) {
    return n < 10 ? "0" + to_string(n) : to_string(n);
}

string to_hour (int count) {
    int h = count / 60;
    int m = count % 60;
    return numify(h) + "h" + numify(m) +"m";
}

int compute_score (int total) {
    if (total == 8) return 100;
    if (total <= 2*60 || total >= 10*60) return 40;
    vector<vector<int>> intervals = {
        {2 * 60, 6 * 60,   40,  60},   
        {6 * 60, 8 * 60,   60, 100},   
        {8 * 60, 9 * 60,  100,  60},   
        {9 * 60, 10 * 60,  60,  40},   
    };
    for (auto temp : intervals) {
        int left = temp[0], right = temp[1];
        int sl = temp[2], sr = temp[3];
        float delta = total - left;
        float i_delta = right - left;
        float s_delta = abs(sr - sl);
        float sg = sr < sl ? -1 : 1;
        if (total >= left && total < right) {
            return sl + sg * (delta * s_delta) / i_delta;   
        }
    }
    return 0;
}

string grade_sleep(int total) {
    int score = compute_score(total);
    string quality = "excellent";
    if (score >= 80 && score < 94) quality = "good";
    if (score >= 60 && score < 79) quality = "fair";
    if (score  < 60) quality = "poor";
    return to_string(score) + ":" + quality; 
}

vector<string> sleepTracker(vector<int> heartRateLog) {
    int score = 0;
    int t1 = 0, t2 = 0, t3 = 0, awake_time = 0;
    vector<string> output;
    for (int n : heartRateLog) {
        if (90 <= n && n <= 100) {
            awake_time++;
            continue;
        }
        if (60 <= n && n <= 89) {
            // rem sleep
            t1++;
        } else if (50 <= n && n <= 59) {
            // light
            t2++;
        } else {
            // deep
            t3++;
        }
    }
    int sleep_count = t1 + t2 + t3;
    output.push_back(to_hour(awake_time));
    output.push_back(to_hour(t1));
    output.push_back(to_hour(t2));
    output.push_back(to_hour(t3));
    cout << "total " << sleep_count << endl;
    output.push_back(to_hour(sleep_count));
    output.push_back(grade_sleep(sleep_count));
    return output;
}
