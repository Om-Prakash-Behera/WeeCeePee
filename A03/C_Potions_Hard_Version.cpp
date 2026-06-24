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

    int sum = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        pq.push(a[i]);

        if (sum < 0) {
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << pq.size() << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
    