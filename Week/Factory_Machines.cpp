#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, t;
    cin >> n >> t;

    int mn = LLONG_MAX;
    vector<int> k(n);
    for (int i=0; i<n; i++){
        cin >> k[i];
        mn = min(mn, k[i]);
    }

    int lo = 0;
    int hi = mn * t;

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int cnt = 0;
        for (int i=0; i<n; i++) {
            cnt += mid / k[i];
        }

        if (cnt >= t) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << "\n";    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}