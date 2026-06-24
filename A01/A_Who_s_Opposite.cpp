#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int n = 2 * abs(a - b);

    if (n == 0 || a > n || b > n || c > n) {
        cout << -1 << "\n";
        return;
    }

    int d = c + n / 2;
    if (d > n) {
        d -= n;
    }
    cout << d << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
    