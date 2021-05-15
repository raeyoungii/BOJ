#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll adv[360000];

int strToSec(string s) {
    int ret = 0;
    string hh = s.substr(0, 2);
    string mm = s.substr(3, 2);
    string ss = s.substr(6, 2);
    ret += stoi(hh) * 60 * 60;
    ret += stoi(mm) * 60;
    ret += stoi(ss);
    return ret;
}

string secToStr(int n) {
    string ret;
    int hh = n / (60 * 60);
    int mm = (n / 60) % 60;
    int ss = n % 60;
    if(hh < 10) ret += "0";
    ret = ret + to_string(hh) + ":";
    if(mm < 10) ret += "0";
    ret = ret + to_string(mm) + ":";
    if(ss < 10) ret += "0";
    ret += to_string(ss);
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for (string& l : logs) {
        int begin_time = strToSec(l.substr(0, 8));
        int end_time = strToSec(l.substr(9, 8));
        for (int i = begin_time; i < end_time; i++) adv[i]++;
    }
    int pt = strToSec(play_time);
    int at = strToSec(adv_time);
    int ans = 0;
    ll sum = 0;
    for (int i = 0; i < at; i++) sum += adv[i];
    ll mx = sum;
    for (int i = at; i < pt; i++) {
        sum -= adv[i - at];
        sum += adv[i];
        if (mx < sum) {
            ans = i - at + 1;
            mx = sum;
        }
    }
    answer = secToStr(ans);
    return answer;
}