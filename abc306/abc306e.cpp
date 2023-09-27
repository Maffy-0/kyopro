#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long N, K, Q, X, Y;

int main(void) {
    fast_io();
    cin >> N >> K >> Q;
    vector<long long> A(N);
    multiset<long long> st, st2;
    for (int i = 0; i < K; i++) {
        st.insert(0);
    }
    for (int i = K; i < N; i++) {
        st2.insert(0);
    }
    long long ans = 0;
    for (int i = 0; i < Q; i++) {
        cin >> X >> Y;
        X--;
        if (st.count(A[X])) {
            st.erase(st.find(A[X]));
            ans -= A[X];
        } else {
            st2.erase(st2.find(A[X]));
            ans -= *st.begin();
            st2.insert(*st.begin());
            st.erase(st.begin());
        }
        A[X] = Y;
        st2.insert(A[X]);
        ans += *prev(st2.end());
        st.insert(*prev(st2.end()));
        st2.erase(prev(st2.end()));
        cout << ans << '\n';
    }
    return 0;
}