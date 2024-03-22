#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    string S, T;
    int N;
    cin >> S >> T >> N;
    for (int i = 0; i < N; i++) {
        S.push_back('_');
        S += T;
    }
    cout << S << endl;
    return 0;
}