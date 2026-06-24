#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    int ans = 0;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        min_heap.push(x);

        int mn = min_heap.top();

        if (mn < x) {
            ans += x - mn;
            min_heap.pop();
            min_heap.push(x);
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
    