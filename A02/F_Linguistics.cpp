#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    string s;
    cin >> s;

    int countA = 0, countB = 0;
    for (char ch : s) {
        if (ch == 'A') {
            countA++;
        }
        else {
            countB++;
        }
    }
    if (countA != a + c + d || countB != b + c + d) {
        cout << "NO\n";
        return;
    }
    
    vector<int> ab, ba;
    int rem = 0, rem_ab = 0, cnt_ab = 0, rem_ba = 0, cnt_ba = 0;

    int i = 0, n = s.size();

    while (i < n) {
        int j = i;
        
        while (j + 1 < n && s[j] != s[j + 1]) {
            j++;
        }

        int len = j - i + 1;
        if (s[i] == 'A' && s[j] == 'B') {
            ab.push_back(len / 2);
        } else if (s[i] == 'B' && s[j] == 'A') {
            ba.push_back(len / 2);
        } else {
            rem += len / 2;
        }
        i = j + 1;
    }

    sort(ab.begin(), ab.end());
    sort(ba.begin(), ba.end());

    int needC = c, needD = d;

    for ( int i = 0; i < ab.size(); i++) {
        if (needC > 0) {
            int use = min(ab[i], needC);
            needC -= use;
            ab[i] -= use;
        }
        if (ab[i] > 0) {
            rem_ab += ab[i];
            cnt_ab++;
        }
    }
    for (int i = 0; i < ba.size(); i++) {
        if (needD > 0) {
            int use = min(ba[i], needD);
            needD -= use;
            ba[i] -= use;
        }
        if (ba[i] > 0) {
            rem_ba += ba[i];
            cnt_ba++;
        }
    }

    if (needC + needD > rem + rem_ab + rem_ba - cnt_ab - cnt_ba) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
    