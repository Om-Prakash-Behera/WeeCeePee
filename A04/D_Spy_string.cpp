#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string ans = a[0];
    for (int i = 0; i < m; i++) {
        char c = ans[i];
        
        for (char new_c = 'a'; new_c <= 'z'; new_c++) {
            ans[i] = new_c;
            bool valid = true;

            for (int j = 0; j < n; j++) {
                int diff = 0;
                for (int k = 0; k < m; k++) {
                    if (ans[k] != a[j][k]) {
                        diff++;
                    }
                }
                if (diff > 1) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                cout << ans << "\n";
                return;
            }
        }
        ans[i] = c;
    }

    cout << -1 << "\n";
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
    