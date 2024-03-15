#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int N, X;
    cin >> N >> X;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        if (P[i] == X) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}