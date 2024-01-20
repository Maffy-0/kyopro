#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, M, si, sj;
string A[16], T[201];
vector<pair<int, int>> L;
int i, j;
map<char, vector<pair<int, int>>> dic;

void input();
int calc_cost(int i, int j, int ii, int jj);
void solve();
void output();
void init_dic();


int main(void) {
    fast_io();
    input();
    init_dic();
    solve();
    output();
    return 0;
}

void input() {
    cin >> N >> M;
    cin >> si >> sj;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> T[i];
    }
    sort(T, T + M);
}

void init_dic() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dic[A[i][j]].emplace_back(i, j);
        }
    }
}

void output() {
    int ls = L.size();
    assert(ls >= 0 && ls <= 5000);
    for (int i = 0; i < ls; i++) {
        cout << L[i].first << " " << L[i].second << '\n';
    }
}

int calc_cost(int i, int j, int ii, int jj) {
    if (i == ii && j == jj) {
        return 1;
    }
    return abs(i - ii) + abs(j - jj) + 1;
}

void solve() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 5; j++) {
            int min_cost = 1e9;
            int ansi = -1, ansj = -1;
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    if (A[k][l] == T[i][j] && min_cost > calc_cost(si, sj, k, l)) {
                        min_cost = calc_cost(si, sj, k, l);
                        ansi = k;
                        ansj = l;
                    }
                }
            }
            assert(ansi != -1 && ansj != -1);
            L.emplace_back(ansi, ansj);
            si = ansi, sj = ansj;
        }
    }
}
