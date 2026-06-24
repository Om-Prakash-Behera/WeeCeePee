#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int A = LLONG_MIN, B = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        A = max(A, x[i] + t[i]);
        B = min(B, x[i] - t[i]);
    }
    double x0 = (A + B) / 2.0;

    cout << fixed << setprecision(15) << x0 << "\n";
    
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
    