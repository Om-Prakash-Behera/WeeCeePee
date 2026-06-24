#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> cnt(n + 5, 0);

    for (int i = 0; i < n; i++) {
        if (a[i] <= n) {
            cnt[a[i]]++;
        }
    }

    int mex = 0;

    while (cnt[mex] > 0) {
        mex++;
    }

    vector<int> dp(mex + 1, LLONG_MAX);
    dp[mex] = 0;

    for (int i = mex; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            dp[j] = min(dp[j], dp[i] + j + i * (cnt[j] - 1));
        }
    }

    cout << dp[0] << "\n";
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
    