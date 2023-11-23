#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, M, A[202020], S[202020];

int main(void) {
    fast_io();
    cin >> N >> M;
    set<pair<int, int>> st;
    for (int i = 1; i <= N; i++) {
        st.insert({0, i});
    }
    for (int i = 0; i < M; i++) {
        cin >> A[i];
        st.erase({-S[A[i]], A[i]});
        S[A[i]]++;
        st.insert({-S[A[i]], A[i]});
        auto [a, b] = *st.begin();
        cout << b << '\n';
    }

    return 0;
}