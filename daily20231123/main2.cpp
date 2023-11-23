#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long N, X[202020], Y[202020];
string S;
map<long long, set<long long>> L, R;

int main(void) {
    fast_io();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    cin >> S;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') {
            L[Y[i]].insert(X[i]);
        } else {
            R[Y[i]].insert(-X[i]);
        }
    }
    bool ok = false;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') {
            if (!R[Y[i]].empty()) {
                long long RMax = *R[Y[i]].begin();
                RMax = -RMax;
                if (RMax < X[i]) {
                    ok = true;
                }
            }
        } else {
            if (!L[Y[i]].empty()) {
                long long LMin = *L[Y[i]].begin();
                if (LMin > X[i]) {
                    ok = true;
                }
            }
        }
    }
    puts(ok ? "Yes" : "No");
    return 0;
}