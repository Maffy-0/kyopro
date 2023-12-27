// 74818
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

enum card { NORMAL, FULLPOWER, CANCEL, TRANSFORMATION, INCREASE };
const int SZ = 9;
int N, M, K, T;
vector<int> t(SZ), w(SZ), h(SZ), v(SZ);
vector<int> tt(SZ), ww(SZ), P(SZ);
long money, c, m, r;
int rest = 0;

void input_init();
void input_query();
void output_cm();
void output_r();
void choose_cm();
void choose_r();

int main(void) {
    fast_io();
    input_init();
    while (T--) {
        choose_cm();
        output_cm();
        input_query();
        choose_r();
        output_r();
    }
    return 0;
}

void input_init() {
    cin >> N >> M >> K >> T;
    for (int i = 0; i < N; i++) {
        cin >> t[i] >> w[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> h[i] >> v[i];
    }
}

void input_query() {
    for (int i = 0; i < M; i++) {
        cin >> h[i] >> v[i];
    }
    cin >> money;
    for (int i = 0; i < K; i++) {
        cin >> tt[i] >> ww[i] >> P[i];
    }
}

void output_cm() { cout << c << " " << m << endl; }

void output_r() { cout << r << endl; }

void choose_cm() {
    vector<tuple<double, int, int, card>> V(N);
    // {評価関数・インデックス・カードの効果を適用するプロジェクトの番号}
    for (int i = 0; i < N; i++) {
        switch (t[i]) {
        case card::NORMAL: {
            double eval = -1;
            int now = 0, idx = 0, idxx = -1;
            bool ok = false;
            for (int j = 0; j < M; j++) {
                double e = (double)v[j] / h[j] / h[j];
                if (eval < e) {
                    eval = e;
                    idx = j;
                }
                if (h[j] <= w[i] && now < v[j]) {
                    now = v[j];
                    idxx = j;
                    ok = true;
                }
            }
            if (ok) {
                V[i] = {1e8, i, idxx, card::NORMAL};
            } else {
                V[i] = {eval, i, idx, card::NORMAL};
            }
        } break;
        case card::FULLPOWER:
            {
                double eval = 0;
                for (int j = 0; j < M; j++) {
                    eval += (double)v[j] / h[j];
                }
                V[i] = {eval, i, 0, card::FULLPOWER};
            }
            break;
        case card::CANCEL:
            // 最も大きい残務量をもつ
            {
                double eval = 1e18;
                int idx = 0;
                for (int j = 0; j < M; j++) {
                    double e = (double)v[j] / h[j];
                    if (e < eval) {
                        eval = e;
                        idx = j;
                    }
                }
                V[i] = {eval, i, idx, card::CANCEL};
            }
            break;
        case card::TRANSFORMATION:
            // evalの配列をつくってみる
            {
                vector<double> evals;
                for (int j = 0; j < M; j++) {
                    double e = (double)v[j] / h[j];
                    evals.push_back(e);
                }
                V[i] = {-101, i, 0, card::TRANSFORMATION};
            }
            break;
        case card::INCREASE: {
            if (rest == 20) {
                V[i] = {-1e9, i, 0, card::INCREASE};
            } else {
                V[i] = {1e9, i, 0, card::INCREASE};
            }
        } break;
        default:
            cerr << "Yakan" << endl;
            break;
        }
    }

    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    c = get<1>(V[0]);
    m = get<2>(V[0]);
    if (get<0>(V[0]) == 1e9) {
        rest++;
    }
    cout << "# eval (choose cm): " << get<0>(V[0]) << endl;
    cout << "# card type : " << get<3>(V[0]) << endl;
    return;
}

void choose_r() {
    vector<int> have(5);
    for (int i = 0; i < N; i++) {
        have[t[i]]++;
    }

    bool ok = false;
    int costp = 1e9, idx = -1;
    for (int i = 0; i < K; i++) {
        if (tt[i] == card::INCREASE && T >= 400) {
            if (costp > P[i] && P[i] < money) {
                ok = true;
                costp = P[i];
                idx = i;
            }
        }
    }
    if (ok && rest <= 20) {
        cout << "# GAGAPI-GAGA" << endl;
        r = idx;
        t[c] = tt[r];
        w[c] = ww[r];
        return;
    }

    vector<pair<double, int>> evals;
    for (int i = 0; i < K; i++) {
        double e = 0;
        if (tt[i] == card::NORMAL) {
            e = ww[i] / (P[i] + 1);
        }
        if (tt[i] == card::FULLPOWER) {
            e = ww[i] * M / (P[i] + 1);
        }
        evals.emplace_back(e, i);
    }

    sort(evals.begin(), evals.end());
    reverse(evals.begin(), evals.end());

    for (int i = 0; i < K; i++) {
        auto [e, id] = evals[i];
        if (P[id] <= money) {
            r = id;
            t[c] = tt[r];
            w[c] = ww[r];
            cout << fixed << setprecision(10) <<  "# eval(choose r) " << e << endl;
            break;
        }
    }
    return;
}