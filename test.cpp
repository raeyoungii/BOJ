#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const char nl = '\n';

int A[4][4];

void copyBoard(int a[][4], int b[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = b[i][j];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            A[i][j] = a++;
        }
    }
    int B[4][4];
    copyBoard(B, A);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << B[i][j] << ' ';
        }cout << nl;
    }
    return 0;
}
