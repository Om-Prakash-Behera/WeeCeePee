#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i].second;
    }

    sort(d.begin(), d.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    vector<int> suffix(n + 1, 0);  
    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + d[i].second;
    }
    

    vector<int> T(n + 1, 0);
    T[0] = suffix[0];
    for (int i = 0; i < n; i++) {
        T[i + 1] = max(d[i].first, suffix[i + 1]);
    }
    cout << *min_element(T.begin(), T.end()) << "\n";
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
    