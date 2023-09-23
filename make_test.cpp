#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

void make_test() {
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    // dist_N(x, y) ... x以上y以下の値をランダムに発生（例の場合4以上10以下）
    uniform_int_distribution<int> dist_N(4, 10), dist_A(1, 20);
    int N = dist_N(rnd);
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = dist_A(rnd);
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] << " \n"[i == N - 1];
    }
}

int main(void) {
    fast_io();
    make_test();
    return 0;
}