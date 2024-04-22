#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

void solve() {
    int N;
    cin >> N;
    unordered_set<int> st;
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            st.insert(i);
            st.insert(N / i);
        }
    }
    cout << (st.size() & 1 ? "P" : "K") << endl; 
}

signed main(void) {
    fast_io();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}