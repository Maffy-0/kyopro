#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    unordered_set<string> st;
    for (int i = 0; i < M; i++) {
        cin >> T[i];
        st.insert(T[i]);
    }
    sort(S.begin(), S.end());

    string now = "";
    auto f = [&](auto f, int i) -> void {
        if (now.size() > 16) return;
        if (i == (int) S.size()) {
            if (now.size() < 3) return;
            if (!st.count(now)) {
                cout << now << endl;
                exit(0);
            }
            return;
        }
        if (i > 0) {
            now += '_';
            f(f, i);
            now.pop_back();
        }
        if (i == 0 || now.back() == '_') {
            now += S[i];
            f(f, i + 1);
            for (int j = 0; j < (int)S[i].size(); j++) {
                now.pop_back();
            }
        }
    };
    do {
        f(f, 0);
    } while (next_permutation(S.begin(), S.end()));
    cout << "-1\n";
    return 0;
}