#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

// メモ化再帰
int h, w;
int a[2020][2020];
bool vis[2020][2020];
int memo[2020][2020];

int f(int i, int j) {
    if (i == h - 1 && j == w - 1) {
        return 0;
    }
    if (vis[i][j]) {
        return memo[i][j];
    }
    vis[i][j] = true;
    int res = -1e9;
    if (j < w - 1) {
        res = max(res, a[i][j + 1] - f(i, j + 1));
    } 
    if (i < h - 1) {
        res = max(res, a[i + 1][j] - f(i + 1, j));
    }
    return memo[i][j] = res;
}

int main(void) {
    fast_io();
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            a[i][j] = s[i][j] == '+' ? 1 : -1;
        }
    }
    int score = f(0, 0);
    if (score == 0) {
        cout << "Draw\n";
    } else if (score < 0) {
        cout << "Aoki\n";
    } else {
        cout << "Takahashi\n";
    }
    return 0;
}