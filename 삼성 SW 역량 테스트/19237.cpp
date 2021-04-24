#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const char nl = '\n';
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

struct Shark {
    int num, dir;
    Shark(int _num, int _dir) : num(_num), dir(_dir) {};
};

int N, M, k;
// dir[상어번호][상어방향][우선순위]
int dir[401][4][4];
vector<Shark> shark[20][20];
int sharkNum[20][20];
int scent[20][20];

bool compare(const Shark& s1, const Shark& s2) { return s1.num < s2.num; }

void moveShark() {
    vector<Shark> tmpShark[20][20];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!shark[i][j].empty()) {
                Shark& cur = shark[i][j][0];
                bool ok = false;
                for (int d = 0; d < 4; d++) {
                    int ny = i + dy[dir[cur.num][cur.dir][d]];
                    int nx = j + dx[dir[cur.num][cur.dir][d]];
                    if (0 <= ny && ny < N && 0 <= nx && nx < N) {
                        if (!sharkNum[ny][nx]) {
                            tmpShark[ny][nx].emplace_back(cur.num, dir[cur.num][cur.dir][d]);
                            ok = true;
                            break;
                        }
                    }
                }
                if (!ok) {
                    for (int d = 0; d < 4; d++) {
                        int ny = i + dy[dir[cur.num][cur.dir][d]];
                        int nx = j + dx[dir[cur.num][cur.dir][d]];
                        if (0 <= ny && ny < N && 0 <= nx && nx < N) {
                            if (sharkNum[ny][nx] == cur.num) {
                                tmpShark[ny][nx].emplace_back(cur.num, dir[cur.num][cur.dir][d]);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            shark[i][j].clear();
            for (auto& x : tmpShark[i][j]) shark[i][j].emplace_back(x.num, x.dir);
        }
    }
}

void removeShark() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (shark[i][j].size() > 1) {
                sort(shark[i][j].begin(), shark[i][j].end(), compare);
                for (int l = 0; l < shark[i][j].size() - 1; l++) {
                    shark[i][j].pop_back();
                }
            }
        }
    }
}

void moveScent() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!shark[i][j].empty()) {
                Shark& cur = shark[i][j][0];
                sharkNum[i][j] = cur.num;
                scent[i][j] = k;
            } else if (scent[i][j]) {
                scent[i][j]--;
                if (!scent[i][j]) sharkNum[i][j] = 0;
            }
        }
    }
}

bool checkShark() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!shark[i][j].empty() && shark[i][j][0].num != 1) return true;
        }
    }
    return false;
}

int solve() {
    int t = 0;
    while(checkShark()) {
        moveShark();
        removeShark();
        moveScent();
        t++;
        if (t > 1000) return -1;
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> k;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x; cin >> x;
            sharkNum[i][j] = x;
            if (x) scent[i][j] = k;
        }
    }
    vector<int> d(M + 1);
    for (int i = 1; i <= M; i++) {
        int x; cin >> x;
        d[i] = x - 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x = sharkNum[i][j];
            if (x) shark[i][j].emplace_back(x, d[x]);
        }
    }
    for (int s = 1; s <= M; s++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int x; cin >> x;
                dir[s][i][j] = x - 1;
            }
        }
    }
    cout << solve() << nl;
    return 0;
}
