#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N;
set<int> s;

int main(void) {
    fast_io();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    if (s.size() == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}