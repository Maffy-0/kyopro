#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, L, A;

int main(void) {
    fast_io();
    cin >> N >> L;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (A >= L) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}