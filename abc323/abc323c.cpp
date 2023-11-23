#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, M, A[101];
string S[101];

int main(void) {
    fast_io();
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    vector T(N, vector<int> (M));
    vector<int> point(N);
    int mx = 0;
    for (int i = 0; i < N; i++) {
        point[i] = i + 1;
        for (int j = 0; j < M; j++) {
            if (S[i][j] == 'o') {
                T[i][j] = 1;
                point[i] += A[j];
            }
        }
        mx = max(mx, point[i]);
    }

    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        if (mx <= point[i]) {
            ans[i] = 0;
        } else {
            vector<int> cur;
            for (int j = 0; j < M; j++) {
                if (!T[i][j]) {
                    cur.push_back(A[j]);
                }
            }
            sort(cur.rbegin(), cur.rend());
            int L = cur.size();
            for (int j = 0; j < L; j++) {
                point[i] += cur[j];
                ans[i]++;
                if (point[i] >= mx) {
                    break;
                } 
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}