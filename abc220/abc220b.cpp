#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long K, A, B;

long long Kto10(long long x) {
    string s = to_string(x);
    int n = s.size();
    long long res = 0;
    int j = 1;
    for (int i = n - 1; i >= 0; i--) {
        res += (s[i] - '0') * j;
        j *= K;
    }
    return res;
}

int main(void) {
    fast_io();
    cin >> K >> A >> B;
    long long a = Kto10(A);
    long long b = Kto10(B);
    cout << a * b << endl;
    return 0;
}