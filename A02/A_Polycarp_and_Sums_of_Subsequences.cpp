#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    vector<int> b(7);
    for (int i = 0; i < 7; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    cout << b[0] << " " << b[1] << " " << b[6] - b[0] - b[1] << "\n";

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
    