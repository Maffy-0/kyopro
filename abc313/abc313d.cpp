#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, K, T;

int ask(const vector<int> &v) {
    cout << "? ";
    for (auto x : v) {
        cout << x + 1 << " ";
    }
    cout << endl;
    cin >> T;
    return T;
}

int main(void) {
    fast_io();
    cin >> N >> K;
    vector<int> A(N, -1);

    int sum = 0;
    vector<int> res(N);
    for (int i = 0; i < K + 1; i++) {
        vector<int> v;
        for (int j = 0; j < K + 1; j++) {
            if (i != j) {
                v.push_back(j);
            }
        }
        res[i] = ask(v);
        sum ^= res[i];
    }

    for (int i = 0; i < K + 1; i++) {
        A[i] = sum ^ res[i];
    }

    for (int i = K + 1; i < N; i++) {
        vector<int> v;
        v.push_back(i);
        int sub = 0;
        for (int j = 0; j < K - 1; j++) {
            sub ^= A[j];
            v.push_back(j);
        }
        res[i] = ask(v);
        A[i] = sub ^ res[i];
    }

    cout << "! ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}