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
    string S;
    cin >> S;
    set<string> st;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            string T = S.substr(i, j - i + 1);
            st.insert(T);
        }
    }
    cout << st.size() << endl;
    return 0;
}