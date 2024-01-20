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
    vector<long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long> B(N), C(N);
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        B[i] = cnt;
        if (A[i] <= A[i + 1] && cnt <= A[i + 1]) cnt++;
        else cnt = 0;
    }
    B[N - 1] = cnt;
    reverse(A.begin(), A.end());
    for (int i = 0; i < N - 1; i++) {
        C[i] = cnt;
        if (A[i] <= A[i + 1] && cnt <= A[i + 1]) cnt++;
        else cnt = 0;
    }
    C[N - 1] = cnt;
    reverse(C.begin(), C.end());
    long ans = 1;
    for (int i = 0; i < N; i++) {
        ans = max(ans, min(B[i], C[i]));
    }
    ans = min(ans, *max_element(A.begin(), A.end()));
    ans = min(ans, (N + 1) / 2);
    cout << ans << endl;
    return 0;
}