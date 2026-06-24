#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    int x = 0, y = 0;
    int place = 1;
    bool turn = true;

    while (n) {
        int d = n % 10;
        n /= 10;

        if (d%2 == 0) {
                x += place * (d / 2);
                y += place * (d / 2);
        } else {
            if (turn) {
                x += place * (d / 2 + 1);
                y += place * (d / 2);
            } else {
                x += place * (d / 2);
                y += place * (d / 2 + 1);
            }
            turn = !turn;
        }
        place *= 10;
    }
    cout << x << " " << y << "\n";

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
    