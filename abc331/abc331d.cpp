#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long N, Q;
string S[1010];
long a, b, c, d;
long rui[1010][1010];
long ni, nj;
long ans;

int main(void) {
    fast_io();
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rui[i + 1][j + 1] = rui[i][j + 1] + rui[i + 1][j] - rui[i][j] + (S[i][j] == 'B');
        }
    }
    
    auto f = [&] (int i, int j) -> long {
        return rui[i][j];
    }; 

    auto g = [&] (int i, int j) -> long {
        ni = i / N, nj = j / N;
        long res = 0;
        res += f(N, N) * ni * nj;
        res += f(i % N, N) * nj;
        res += f(N, j % N) * ni;
        res += f(i % N, j % N);
        return res;
    };

    while (Q--) {
        cin >> a >> b >> c >> d;
        ans = g(a, b) + g(c + 1, d + 1) - g(a, d + 1) - g(c + 1, b);
        cout << ans << '\n';
    }
    return 0;
}