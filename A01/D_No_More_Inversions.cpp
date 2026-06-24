#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int m = n - k;

    for (int i = 1; i < k - m; i++) {
        cout << i << " ";
    }
    for (int i = k; i >= k - m; i--) {
        cout << i << " ";
    }
    cout << "\n";
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
    