#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int N;
    cin >> N;
    bool flag = true;
    set<string> st;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if (st.count(S)) flag = false;
        st.insert(S);
        bool ok = false, ok2 = false;
        string T = "HDCS", U = "A23456789TJQK";
        for (char c : T) if (c == S[0]) ok = true;
        for (char c : U) if (c == S[1]) ok2 = true;
        flag &= (ok && ok2);
    }
    cout << (flag ? "Yes\n" : "No\n");
    return 0;
}