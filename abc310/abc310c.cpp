#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n;
    cin >> n;
    set<string> st;
    int ans = n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (st.count(s)) {
            ans--;
        } else {
            st.insert(s);
            string t = s;
            reverse(t.begin(), t.end());
            st.insert(t);
        }
    }
    cout << ans << endl;
    return 0;
}