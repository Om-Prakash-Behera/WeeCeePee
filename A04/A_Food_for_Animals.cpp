#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if (max(0LL, x - a) + max(0LL, y - b) <= c) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
    