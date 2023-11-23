#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, Q;
long long C[202020];
vector<unordered_set<long long>> vs(202020);

int main(void) {
    fast_io();
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        vs[i].insert(C[i]);
    }
    while (Q--) {
        long long a, b;
        cin >> a >> b;
        a--, b--;
        if (vs[a].size() > vs[b].size()) {
            swap(vs[a], vs[b]);
        }
        vs[b].merge(vs[a]);
        vs[a].clear();
        cout << vs[b].size() << '\n';
    }
    return 0;
}