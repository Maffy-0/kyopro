#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long K;
vector<long long> ans;

void dfs(long long x) {
    if (x >= 1e18) {
        return;
    }
    ans.push_back(x);
    int y = x % 10;
    for (int i = y - 1; i >= 0; i--) {
        dfs(x * 10 + i);
    }
};

int main(void) {
    fast_io();
    cin >> K;
    for (int i = 1; i <= 9; i++) {
        dfs(i);
    }
    sort(ans.begin(), ans.end());
    cout << ans[K - 1] << endl;
    return 0;
}