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
    int N;
    cin >> N;
    vector<int> H(N);
    int res = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        if (res < H[i]) {
            res = H[i];
            ans = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}