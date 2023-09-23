#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

const int N = 10;
int Q;
string S[N];
int A[10][10];

int main(void) {
    fast_io();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1;
        }
    }
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            A[i][j] = 2;
        }
    }
    for (int i = 2; i < N - 2; i++) {
        for (int j = 2; j < N - 2; j++) {
            A[i][j] = 3;
        }
    }
    for (int i = 3; i < N - 3; i++) {
        for (int j = 3; j < N - 3; j++) {
            A[i][j] = 4;
        }
    }
    for (int i = 4; i < N - 4; i++) {
        for (int j = 4; j < N - 4; j++) {
            A[i][j] = 5;
        }
    }
    cin >> Q;
    while (Q--) {
        int ans = 0;
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (S[i][j] == 'X') {
                    ans += A[i][j];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}