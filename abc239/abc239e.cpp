#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

const int MX = 101010;
int N, Q, X[MX];
vector<int> G[MX];

int main(void) {
    fast_io();
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    

    while (Q--) {
        int v, k;
        cin >> v >> k;
        v--;
        set<int> st = ans[v];
        cout << st.lower_bound(k) << '\n';
    }
    return 0;
}