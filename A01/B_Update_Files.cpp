#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int installed = 1;
    int hrs = 0;

    while (installed < k && installed < n) {
        installed *= 2;
        hrs++;
    }

    if (installed < n) {
        int remaining = n - installed;
        hrs += (remaining + k - 1) / k;
    }
    
    cout << hrs << "\n";
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
    