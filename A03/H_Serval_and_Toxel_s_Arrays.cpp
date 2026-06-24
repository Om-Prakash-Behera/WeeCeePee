#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);

    int M = n + m + 5;

    vector<pair<int, int>> intervals(M, {-1, 0});

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        intervals[a[i]].first = 0;
    }

    for (int i = 1; i <= m; i++) {
        int p, v;
        cin >> p >> v;

        int old = a[p];

        intervals[old].second += i - intervals[old].first;
        intervals[old].first = -1;

        a[p] = v;
        intervals[v].first = i;
    }

    for (int i = 1; i < M; i++) {
        if (intervals[i].first != -1) {
            intervals[i].second += m + 1 - intervals[i].first;
        }
    }

    int ans = n * m * (m + 1);

    for (int i = 1; i < M; i++) {
        ans -= intervals[i].second * (intervals[i].second - 1) / 2;
    }

    cout << ans << "\n";

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
    