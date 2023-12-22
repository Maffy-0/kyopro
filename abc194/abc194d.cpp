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
    long double ans = 0;
    for (int i = 1; i < N; i++) {
        ans += (long double) N / (N - i);
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}