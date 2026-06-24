#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m; 
    cin >> n >> m;

    // graph template
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> topic(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> topic[i];
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 1);

    sort(order.begin(), order.end(), [&](int a, int b) {
        return topic[a] < topic[b];
    });

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int u = order[i];
        set<int> seen;

        for (int v : adj[u]) {
            if (topic[v] == topic[u]) {
                cout << -1 << "\n";
                return;
            }

            if (topic[v] < topic[u]) {
                seen.insert(topic[v]);
            }
        }
        
        if (seen.size() != topic[u] - 1) {
            cout << -1 << endl;
            return;
        }
        ans.push_back(u);
    }

    for (int u : ans) {
        cout << u << " ";
    }
    cout << "\n";
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
    