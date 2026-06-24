#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, T, a, b;
    cin >> n >> T >> a >> b;

    int easy = 0, hard = 0;

    vector<pair<int, int>> qns(n);
    for (int i = 0; i < n; i++) {
        cin >> qns[i].first;
        if (qns[i].first == 0) {
            easy++;
        } else {
            hard++;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> qns[i].second;
    }
    sort(qns.begin(), qns.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    });
    qns.push_back({0, T + 1});

    int easy_done = 0, hard_done = 0;
    int ans = 0;
    
    for (int i = 0; i < n + 1; i++) {

        if (i == 0 || qns[i].second != qns[i - 1].second) {
            int time_left = qns[i].second - 1;

            int used = easy_done * a + hard_done * b;
            
            if (used <= time_left) {
                int rem = time_left - used;

                int easy_ext = min(easy - easy_done, rem / a);
                rem -= easy_ext * a;

                int hard_ext = min(hard - hard_done, rem / b);
                
                ans = max(ans, easy_done + hard_done + easy_ext + hard_ext);
            }
        }

        if (i == n) {
            break;
        }
        
        if (qns[i].first == 0) {
            easy_done++;
        } else {
            hard_done++;
        }
    }

    cout << ans << "\n";
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
    