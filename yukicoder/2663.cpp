#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N, M;
    cin >> N >> M;
    int cnt = 0;
    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j < 1 << M; j++) {
            cout << cnt << " \n"[j + 1 == 1 << M];
            cnt++;
        }
    }    
    return 0;
}