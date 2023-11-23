#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N;
string S[505050], T;

int main() {
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    vector<int> ans;
    int M = T.size();
    for (int i = 0; i < N; i++) {
        int L = S[i].size();
        if (S[i] == T) {
            ans.push_back(i + 1);
        } else if (abs(L - M) <= 1) {
            int j = 0;
            while (j < M && j < L) {
                if (S[i][j] == T[j]) {
                    j++;
                } else {
                    break;
                }
            }
            int k = 0;
            while (k < M && k < L) {
                if (S[i][L - 1 - k] == T[M - 1 - k]) {
                    k++;
                } else {
                    break;
                }
            }
            if (j + k + 1 >= L && j + k + 1 >= M) {
                ans.push_back(i + 1);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}