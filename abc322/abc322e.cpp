#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

long long N, K, P;
long long dp[101][6][6][6][6][6];

void init() {
    for (int i = 0; i <= 100; i++) {
        for (int a = 0; a <= 5; a++) {
            for (int b = 0; b <= 5; b++) {
                for (int c = 0; c <= 5; c++) {
                    for (int d = 0; d <= 5; d++) {
                        for (int e = 0; e <= 5; e++) {
                            dp[i][a][b][c][d][e] = 1e18;
                        }
                    }
                }
            }
        }
    }
    dp[0][0][0][0][0][0] = 0;
}

void output(){
    for (int i = 0; i <= N; i++) {
        cout << dp[i][P][P][P][0][0] << endl;
    }
}

int main(void) {
    fast_io();
    cin >> N >> K >> P;
    init();
    for (int i = 0; i < N; i++) {
        long long C;
        cin >> C;
        vector<long long> A(K);
        for (int j = 0; j < K; j++) {
            cin >> A[j];
        }
        for (long long a = 0; a <= 5; a++) {
            for (long long b = 0; b <= 5; b++) {
                for (long long c = 0; c <= 5; c++) {
                    for (long long d = 0; d <= 5; d++) {
                        for (long long e = 0; e <= 5; e++) {
                            long long now = dp[i][a][b][c][d][e];
                            chmin(dp[i + 1][a][b][c][d][e], now);
                            chmin(dp[i + 1][min(a + A[0], P)][b][c][d][e],
                                  now + C);
                            if (K >= 2)
                                chmin(dp[i + 1][min(a + A[0], P)][min(b + A[1], P)][c][d][e],
                                      now + C);
                            if (K >= 3)
                                chmin(dp[i + 1][min(a + A[0], P)][min(b + A[1], P)][min(c + A[2], P)][d][e],
                                      now + C);
                            if (K >= 4)
                                chmin(dp[i + 1][min(a + A[0], P)][min(b + A[1], P)][min(c + A[2], P)][min(d + A[3], P)][e],
                                      now + C);
                            if (K >= 5)
                                chmin(dp[i + 1][min(a + A[0], P)][min(b + A[1], P)][min(c + A[2], P)][min(d + A[3], P)][min(e + A[4], P)],
                                      now + C);
                        }
                    }
                }
            }
        }
    }

    if (K == 5) {
        long long ans = 1e18;
        for (int a = P; a <= 5; a++) {
            for (int b = P; b <= 5; b++) {
                for (int c = P; c <= 5; c++) {
                    for (int d = P; d <= 5; d++) {
                        for (int e = P; e <= 5; e++) {
                            chmin(ans, dp[N][a][b][c][d][e]);
                        }
                    }
                }
            }
        }
        if (ans == (long long)1e18)
            ans = -1;
        cout << ans << endl;
    } else if (K == 4) {
        long long ans = 1e18;
        for (int a = P; a <= 5; a++) {
            for (int b = P; b <= 5; b++) {
                for (int c = P; c <= 5; c++) {
                    for (int d = P; d <= 5; d++) {
                        for (int e = 0; e <= 5; e++) {
                            chmin(ans, dp[N][a][b][c][d][e]);
                        }
                    }
                }
            }
        }
        if (ans == (long long)1e18)
            ans = -1;
        cout << ans << endl;
    } else if (K == 3) {
        long long ans = 1e18;
        for (int a = P; a <= 5; a++) {
            for (int b = P; b <= 5; b++) {
                for (int c = P; c <= 5; c++) {
                    for (int d = 0; d <= 5; d++) {
                        for (int e = 0; e <= 5; e++) {
                            chmin(ans, dp[N][a][b][c][d][e]);
                        }
                    }
                }
            }
        }
        if (ans == (long long)1e18)
            ans = -1;
        cout << ans << endl;
    } else if (K == 2) {
        long long ans = 1e18;
        for (int a = P; a <= 5; a++) {
            for (int b = P; b <= 5; b++) {
                for (int c = 0; c <= 5; c++) {
                    for (int d = 0; d <= 5; d++) {
                        for (int e = 0; e <= 5; e++) {
                            chmin(ans, dp[N][a][b][c][d][e]);
                        }
                    }
                }
            }
        }
        if (ans == (long long)1e18)
            ans = -1;
        cout << ans << endl;
    } else {
        long long ans = 1e18;
        for (int a = P; a <= 5; a++) {
            for (int b = 0; b <= 5; b++) {
                for (int c = 0; c <= 5; c++) {
                    for (int d = 0; d <= 5; d++) {
                        for (int e = 0; e <= 5; e++) {
                            chmin(ans, dp[N][a][b][c][d][e]);
                        }
                    }
                }
            }
        }
        if (ans == (long long)1e18)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}