#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    map<string, char> mp;
    mp["left"] = 'L'; mp["right"] = 'R';
    int left = 10, right = 12;
    for (int& n : numbers) {
        char ch;
        if (n % 3 == 1) ch = 'L';
        else if (n && n % 3 == 0) ch = 'R';
        else {
            if (!n) n = 11;
            int ld = abs(n - left) / 3 + abs(n - left) % 3;
            int rd = abs(n - right) / 3 + abs(n - right) % 3;
            if (ld < rd) ch = 'L';
            else if (ld > rd) ch = 'R';
            else ch = mp[hand];
        }
        if (ch == 'L') left = n;
        else if (ch == 'R') right = n;
        answer += ch;
    }
    return answer;
}