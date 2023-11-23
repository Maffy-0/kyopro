#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, cnt[10], now[10];
string S;

int main(void) {
    fast_io();
    cin >> N >> S;
    for (char c : S) {
        cnt[c - '0']++;
    }
    int ans = 0;
    for (long long s = 0; ; s++) {
        long long t = s * s;
        for (int i = 0; i < 10; i++) {
            now[i] = 0;
        } 
        int d = 0;
        while (t > 0) {
            d++;
            now[t % 10]++;
            t /= 10;
        }
        if (d > N) {
            break;
        }
        now[0] += N - d;
        bool ok = true;
        for (int i = 0; i < 10; i++) {
            if (cnt[i] != now[i]) {
                ok = false;
            }
        }
        if (ok) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}