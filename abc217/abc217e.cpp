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
    int Q;
    cin >> Q;

    multiset<int> st;
    deque<int> q;
    while (Q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            cin >> x;
            q.push_back(x);
        } else if (c == 2) {
            if (!st.empty()) {
                cout << *st.begin() << '\n';
                st.erase(st.begin());
            } else {
                cout << q.front() << '\n';
                q.pop_front();
            }
        } else {
            st.insert(q.begin(), q.end());
            q.clear();
        }
    }
    return 0;
}