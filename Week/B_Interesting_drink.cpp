#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    
    int q;
    cin >> q;

    while (q--) {
        int m;
        cin >> m;
        int idx = upper_bound(prices.begin(), prices.end(), m) - prices.begin();
        cout << idx << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}