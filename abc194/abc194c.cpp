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
    vector<int> A(404);
    long ans = 0;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        p += 200;
        A[p]++;
    }
    for (int i = 0; i <= 400; i++) {
        for (int j = 0; j <= 400; j++) {
            ans += (long) A[i] * A[j] * (i - j) * (i - j);
        }
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}