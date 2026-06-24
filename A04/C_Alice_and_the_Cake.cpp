#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    
    int w = 0;
    priority_queue<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push(x);
        w += x;
    }

    priority_queue<int> pq;
    pq.push(w);

    while (!pq.empty() && !a.empty()) {
        int max_a = a.top();
        int max_pq = pq.top();

        if (max_a == max_pq) {
            a.pop();
            pq.pop();
        } else if (max_a < max_pq) {
            pq.pop();
            pq.push(max_pq / 2);
            pq.push((max_pq + 1) / 2);
        } else {
            break;
        }
    }

    if (a.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
    