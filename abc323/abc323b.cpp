#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N;
string S[101];

int main(void) {
    fast_io();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    vector<pair<int, int>> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i].second = -i;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'o') {
                ans[i].first++;
            } else if (S[i][j] == 'x') {
                ans[i].first--;
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
    for (int i = 0; i < N; i++) {
        cout << -ans[i].second + 1 << " \n"[i == N - 1];
    }
    return 0;
}