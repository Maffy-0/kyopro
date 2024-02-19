#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    long H, W, N;
    cin >> H >> W >> N;
    vector<long> A(N);
    long count = 0L;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        count += 1L << A[i];
    }
    if (count > H * W) {
        cout << "No\n";
        return 0;
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    multiset<pair<long, long>> st;
    st.insert(minmax(H, W));
    for (int i = 0; i < N; i++) {
        if (st.empty()) {
            cout << "No\n";
            return 0;
        }
        // cout << "i : " << i << endl;
        // for (auto [n, m] : st) {
        //     cout << n << " " << m << endl;
        // }
        long now = 1 << A[i];
        // cout <<"now : " << now << endl;
        auto it = st.lower_bound(make_pair(now, now));
        if (it == st.end()) {
            cout << "No\n";
            return 0;
        }
        st.erase(it);
        auto [a, b] = *it;
        // cout << "a, b ; " << a << " " << b << endl;
        if (a - now > 0 && b - now > 0) {
            if (min(a, b - now) >= min(b, a - now)) {
                st.insert(minmax(a, b - now));
                st.insert(minmax(now, a - now));
            } else {
                st.insert(minmax(b, a - now));
                st.insert(minmax(now, b - now));
            }
        } else {
            if (a - now > 0 && now > 0) {
                st.insert(minmax(a - now, now));
            }
            if (b - now > 0 && now > 0) {
                st.insert(minmax(b - now, now));
            }
        }
    }
    cout << "Yes\n";
    return 0;
}