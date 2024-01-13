#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N;

bool inside(int i) { return i >= 0 && i < N; }

bool ok(int i, int j) { return inside(i) && inside(j); }

int main(void) {
    fast_io();
    cin >> N;
    const int inf = 1e9;
    vector<vector<int>> ans(N, vector<int>(N, inf));
    int state = 0;
    int i = 0, j = 0;
    int cnt = 1;

    while (1) {
        while (1) {
            if (ans[i][j] == inf) {
                cout << i << " " << j << endl;
                ans[i][j] = cnt;
                cnt++;
                if (state == 0 && ok(i, j)) {
                    j++;
                } else {
                    state++;
                    j--;
                    break;
                }
                if (state == 1 && ok(i, j)) {
                    i++;
                } else {
                    state++;
                    i--;
                    break;
                }
                if (state == 2 && ok(i, j)) {
                    j--;
                } else {
                    state++;
                    j++;
                    break;
                }
                if (state == 3 && ok(i, j)) {
                    i--;
                } else {
                    state++;
                    i--;
                    break;
                }
            } else {
                break;
            }
        }
        if (i == N / 2 && j == N / 2) break;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == N / 2 && j == N / 2) {
                cout << 'T' << " ";
            } else {
                cout << ans[i][j] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}