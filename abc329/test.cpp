#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N = 200000;

int make_test(int x, int y) {
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    // dist_N(x, y) ... x以上y以下の値をランダムに発生（例の場合4以上10以下）
    uniform_int_distribution<int> A(x, y);
    int N = A(rnd);
    return N;
}

int main(void) {
    fast_io();
    cout << N << " " << N << endl;
    for (int i = 0; i < N; i++) {
        cout << make_test(1, N) << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        int a = make_test(1, 200000);
        int b = make_test(1, 200000);
        while(b == a) b = make_test(1, 200000);
        cout << a << " " << b << endl; 
    }
    return 0;
}