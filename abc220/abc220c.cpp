#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long N, X, A[101010], S[101010];

int main(void) {
    fast_io();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> X;
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    long long ans = 0LL;
    long long Y = X / S[N];
    ans += Y * N;
    long long Z = X - S[N] * Y;
    for (int i = 1; i <= N; i++) {
        if (Z < S[i]) {
            ans += i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}