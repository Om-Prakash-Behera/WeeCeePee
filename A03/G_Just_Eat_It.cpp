#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    int tot = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }

    int a1 = LLONG_MIN, cur1 = 0;

    for (int i = 0; i < n - 1; i++) {
        cur1 += a[i];
        a1 = max(a1, cur1);
        if (cur1 < 0) {
            cur1 = 0;
        }
    }

    int a2 = LLONG_MIN, cur2 = 0;

    for (int i = 1; i < n; i++) {
        cur2 += a[i];
        a2 = max(a2, cur2);
        if (cur2 < 0) {
            cur2 = 0;
        }
    }

    if (tot > max(a1, a2)) {
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
    