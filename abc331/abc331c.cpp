#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N;
int A[202020];

int main(void) {
    fast_io();
    cin >> N;
    vector<long long> b(1010101);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        b[A[i]]++;
    }
    vector<long long> S(1010101);
    for (long long i = 1010101; i >= 1; i--) {
        S[i - 1] = S[i] + b[i] * i;
    }
    for (int i = 0; i < N; i++) {
        cout << S[A[i]] << " \n"[i == N - 1];
    }
    return 0;
}
