#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long> A(2 * N);
        rep(i, 2 * N) {
            cin >> A[i];
        }

        long sum = 0;
        rep(i, 2 * N) sum += A[i];

        priority_queue<long> pq;
        rep(i, 2 * N) {
            pq.push(A[i]);
            int can = (i + 1) / 2;
            if ((int)pq.size() > can) {
                pq.pop();
            }
        }

        long lost = 0;
        while (!pq.empty()) {
            lost += pq.top();
            pq.pop();
        }
        long ans = sum - lost;
        cout << ans << '\n';
        
    }
    return 0;
}