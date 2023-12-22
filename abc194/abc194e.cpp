#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    set<int> st;
    for (int i = 0; i <= N; i++) {
        st.insert(i);
    }
    vector<int> mp(N + 1);
    for (int i = 0; i < M; i++) {
        if (st.count(A[i])) {
            st.erase(A[i]);
        }
        mp[A[i]]++;
    }
    int ans = *st.begin();
    for (int i = M; i < N; i++) {
        if (mp[A[i - M]] == 1) {
            st.insert(A[i - M]);
        }
        if (st.count(A[i])) {
            st.erase(A[i]);
        }
        ans = min(ans, *st.begin());
        mp[A[i - M]]--;
        mp[A[i]]++;
    }
    cout << ans << '\n';
    return 0;
}