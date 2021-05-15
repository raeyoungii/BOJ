#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int gi[110][110];
int bo[110][110];

bool checkGi(int x, int y) {
    if (y == 1 || gi[x][y - 1] || bo[x - 1][y] || bo[x][y]) return true;
    return false;
}

bool checkBo(int x, int y) {
    if (gi[x][y - 1] || gi[x + 1][y - 1] || (bo[x - 1][y] && bo[x + 1][y])) return true;
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for (auto& bf : build_frame) {
        int x = bf[0] + 1, y = bf[1] + 1, a = bf[2], b = bf[3];
        if (b == 1) {
            if (a == 0 && checkGi(x , y)) gi[x][y] = 1;
            else if (a == 1 && checkBo(x, y)) bo[x][y] = 1;
        } else {
            if (a == 0) {
                gi[x][y] = 0;
                if (gi[x][y + 1] && !checkGi(x, y + 1)) gi[x][y] = 1;
                else if (bo[x - 1][y + 1] && !checkBo(x - 1, y + 1)) gi[x][y] = 1;
                else if (bo[x][y + 1] && !checkBo(x, y + 1)) gi[x][y] = 1;
            } else if (a == 1) {
                bo[x][y] = 0;
                if (gi[x][y] && !checkGi(x, y)) bo[x][y] = 1;
                else if (gi[x + 1][y] && !checkGi(x + 1, y)) bo[x][y] = 1;
                else if (bo[x - 1][y] && !checkBo(x - 1, y)) bo[x][y] = 1;
                else if (bo[x + 1][y] && !checkBo(x + 1, y)) bo[x][y] = 1;
            }
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
            if (gi[i][j]) answer.push_back({i - 1, j - 1, 0});
            if (bo[i][j]) answer.push_back({i - 1, j - 1, 1});
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 5;
    vector<vector<int>> build_frame = {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1},
                                       {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}};
    vector<vector<int>> ans = solution(n, build_frame);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        printf("[%d, %d, %d]", ans[i][0], ans[i][1], ans[i][2]);
        cout << ",]" [i == ans.size() - 1];
    }
    return 0;
}
