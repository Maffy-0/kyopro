#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int vis[61][61][61][61];
signed main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    pair<int, int> p = {-1, -1}, q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'P') {
                if (p == pair<int, int>{-1, -1}) {
                    p = {i, j};
                } else {
                    q = {i, j};
                    break;
                }
            }
        }
    }

    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};

    auto eq = [&](pair<int, int> a, pair<int, int> b) {
        return (a.first == b.first) && (a.second == b.second);
    };

    auto canMove = [&](int i, int j) {
        return (i >= 0 && i < N) && (j >= 0 && j < N) && S[i][j] != '#';
    };

    int ans = 1e9;

    auto f = [&](auto f, pair<int, int> a, pair<int, int> b, int cnt) -> void {
        for (int k = 0; k < 4; k++) {
            auto [ia, ja] = a;
            auto [ib, jb] = b;
            ia += di[k];
            ja += dj[k];
            ib += di[k];
            jb += dj[k];
            if (!canMove(ia, ja) && !canMove(ib, jb))
                continue;
            if (!canMove(ia, ja)) {
                ia -= di[k];
                ja -= dj[k];
            }
            if (!canMove(ib, jb)) {
                ib -= di[k];
                jb -= dj[k];
            }
            pair<int, int> na = {ia, ja};
            pair<int, int> nb = {ib, jb};
            if (eq(na, nb)) {
                ans = min(ans, cnt);
            }
            if (vis[ia][ja][ib][jb] == 1) {
                continue;
            }
            cout << "p : " << ia << " " << ja << " q : " << ja << " " << jb << endl;
            vis[ia][ja][ib][jb] = 1;
            f(f, na, nb, cnt + 1);
        }
    };

    f(f, p, q, 0);
    if (ans == 1e9) ans = -1;
    std::cout << ans << endl;
    return 0;
}