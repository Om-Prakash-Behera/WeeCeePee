#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<int> freq(n+1, 0);
    freq[0] = 1;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        freq[0]++;
        freq[x]--;
    }

    int presses = 0;
    vector<int> res(26, 0);
    for (int i = 0; i < n; i++) {
        presses += freq[i];
        res[s[i] - 'a'] += presses;
    }

    for (int i = 0; i < 26; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
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
    