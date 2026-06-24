#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;

    vector<int> pref(s.size());
    for (int i = 1; i < s.size(); i++) {
        pref[i] = pref[i - 1] + (s[i] == s[i - 1]);
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << pref[r - 1] - pref[l - 1] << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}