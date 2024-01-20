#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    long N;
    cin >> N;
    N--;
    string ans = "";
    vector<int> A = {0, 2, 4, 6, 8};
    while (N != 0) {
        int x = N % 5;
        ans += to_string(A[x]);
        N /= 5;
    }
    reverse(ans.begin(), ans.end());
    if (ans == "") ans = "0";
    cout << ans << endl;
    return 0;
}