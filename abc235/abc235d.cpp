#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

ll ope2(ll x) {
    string sx = to_string(x);
    rotate(sx.rbegin(), sx.rbegin() + 1, sx.rend());
    ll nx = stoll(sx);
    return nx;
}

int main(void) {
    fast_io();
    int a, n;
    cin >> a >> n;
    queue<ll> que;
    que.push(1);
    vector<ll> dist(1010101, -1);
    dist[1] = 0;
    while (!que.empty()) {
        ll x = que.front();
        que.pop();
        ll nx = x * a;
        if (nx < 1000000) {
            if (dist[nx] == -1) {
                dist[nx] = dist[x] + 1;
                que.push(nx);
            }
        }
        if (x >= 10 && x % 10 != 0) {
            ll nx = ope2(x);
            if (dist[nx] == -1) {
                dist[nx] = dist[x] + 1;
                que.push(nx);
            }
        }
    }
    cout << dist[n] << endl;
    return 0;
}