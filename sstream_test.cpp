#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> commands = {"line -n 100 -s hi -e", "lien -s Bye"};
    for (auto& c : commands) {
        istringstream ss(c);
        string stringBuffer;
        vector<string> v;
        while (getline(ss, stringBuffer, ' '))
            v.push_back(stringBuffer);
        for (auto& s : v)
            cout << s << "\n";
    }
    return 0;
}
