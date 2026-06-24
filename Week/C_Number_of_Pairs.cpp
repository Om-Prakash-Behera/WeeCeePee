#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt(vector<int> &a, int x) {
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(a.begin() + i + 1, a.end(), x - a[i]) - a.begin();
        ans += j - i - 1;
    }
    return ans;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];    
    }

    sort(a.begin(), a.end());

    int ans = cnt(a, r) - cnt(a, l - 1);
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