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
    int m;
    cin >> m;
    vector<int> d(m);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> d[i];
        sum += d[i];
    }
    sum = (sum + 1) / 2;
    int cur = 0;
    for (int i = 0; i < m; i++) {
        cur += d[i];
        if (cur >= sum) {
            cur -= d[i];
            cout << i + 1 << endl;
            cout << sum - cur << endl;
            return 0;
        }
    }
    return 0;
}