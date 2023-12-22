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
    vector<long> p;
    long x = 1;
    for (int i = 0; i < 12; i++) {
        p.push_back(x);
        x = x * 10 + 1;
    }

    vector<long> ans;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            for (int k = 0; k < 12; k++) {
                ans.push_back(p[i] + p[j] + p[k]);
            }
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans[N - 1] << endl;
    return 0;
}