#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int N = 10000;

vector<int> factorial(N), inv_factorial(N);

int pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    factorial[0] = 1;
    for (int i = 1; i < N; i++) {
        factorial[i] = (factorial[i - 1] * i) % mod;
    }

    inv_factorial[N - 1] = pow(factorial[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        inv_factorial[i] = (inv_factorial[i + 1] * (i + 1)) % mod;
    }
}

int nCr(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    return (factorial[n] * inv_factorial[r] % mod) * inv_factorial[n - r] % mod;
}

void solve() {
    int n;
    cin >> n;

    int ans = 1;

    for (int k = 1; k <= n; k++) {
        if (2 * k >= n) {
            ans = (ans + (2 * k + 1) * nCr(n, k)) % mod;
            continue;
        }

        for (int i = k + 1; i <= 2 * k + 1; i++) {
            int p = nCr(i - 1, k) * nCr(n - i, 2 * k + 1 - i) % mod;
            ans = (ans + p * i) % mod;
        }
    }

    cout << ans << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
    