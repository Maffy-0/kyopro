#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, M;
int A[202020], B[202020];

int main(void) {
    fast_io();
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    
    return 0;
}