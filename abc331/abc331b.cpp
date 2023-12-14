#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long N, S, M, L;

int main(void) {
    fast_io();
    long long ans = 1e18;
    cin >> N >> S >> M >> L;
    for (long long i = 0; i <= N; i++) {
        for (long long j = 0; j <= N; j++) {
            for (long long k = 0; k <= N; k++) {
                if (6 * i + 8 * j + 12 * k >= N) {
                    ans = min(ans, i * S + j * M + k * L);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}