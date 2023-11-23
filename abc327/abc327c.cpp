#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

const int N = 9;
int A[N][N];

int main(void) {
    fast_io();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    vector<set<int>> a(N), b(N);
    vector<vector<set<int>>> c(3, vector<set<int>> (3));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i].insert(A[i][j]);
            b[j].insert(A[i][j]);
            int k = i / 3, l = j / 3;
            c[k][l].insert(A[i][j]);
        }
    }
    bool ok = true;
    for (int i = 0; i < N; i++) {
        if ((int)a[i].size() != N) ok = false;
        if ((int)b[i].size() != N) ok = false;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((int)c[i][j].size() != N) {
                ok = false;
            }
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}