#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, X, S[10];
long long ans;

int main(void) {
    fast_io();
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        if (S[i] <= X) {
            ans += S[i];
        }
    }
    cout << ans << endl;
    return 0;
}