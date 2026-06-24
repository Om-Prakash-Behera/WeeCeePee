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

    while (!a.empty()) {
        bool possible = false;
        
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] % (i + 2)) {
                a.erase(a.begin() + i);
                possible = true;
                break;
            }
        }

        if (!possible) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
    