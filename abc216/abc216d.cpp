#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n, m;
    cin >> n >> m;
    vector<queue<int>> p(202020);
    vector<vector<int>> ids(202020);
    queue<int> que;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            p[i].push(a);
        }
        int ni = p[i].front();
        ids[ni].push_back(i);
        if (ids[ni].size() == 2) {
            que.push(ni);
        }
    }
    int cnt = 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        cnt++;
        for (int i : ids[u]) {
            p[i].pop();
            if (!p[i].empty()) {
                int ni = p[i].front();
                ids[ni].push_back(i);
                if (ids[ni].size() == 2) {
                    que.push(ni);
                }
            }
        }
    }
    if (cnt >= n) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}