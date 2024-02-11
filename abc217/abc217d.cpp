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
    int L, Q;
    cin >> L >> Q;
    set<int> st;
    st.insert(0);
    st.insert(L);
    while (Q--) {
        int c, x;
        cin >> c >> x;
        if (c == 1) {
            st.insert(x);
        } else {
            auto rit = st.lower_bound(x);
            assert(rit != st.end());
            auto lit = rit;
            lit--;
            assert(rit != st.begin());
            cout << *rit - *lit << '\n';
        }
    }
    return 0;
}