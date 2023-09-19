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
    int N, M;
    cin >> N >> M;
    vector<int> T(M), W(M), S(M);
    for (int i = 0; i < M; i++) {
        cin >> T[i] >> W[i] >> S[i];
    }
    set<int> st;
    for (int i = 0; i < N; i++) {
        st.insert(i);
    }
    vector<ll> ans(N);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    for (int i = 0; i < M; i++) {
        while (!que.empty() && que.top().first <= T[i]) {
            st.insert(que.top().second);
            que.pop();
        }
        if (!st.empty()) {
            int id = *st.begin();
            st.erase(st.begin());
            ans[id] += W[i];
            que.push({T[i] + S[i], id});
        }
    } 
    for (int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}