#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    int ans = 0;
    int l = 0, r = 0;
    while (r < n) {
        if (prefix[r] - prefix[l] + a[l] <= t) {
            ans = max(ans, r - l + 1);
            r++;
        } else {
            l++;
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}