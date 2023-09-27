#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, A;

int main(void) {
    fast_io();
    cin >> N;
    const int M = N * 3;
    map<int, int> mp;
    for (int i = 0; i < M; i++) {
        cin >> A;
        mp[A]++;
        if (mp[A] == 2) {
            cout << A << " ";
        }
    }
    cout << endl;
    return 0;
}