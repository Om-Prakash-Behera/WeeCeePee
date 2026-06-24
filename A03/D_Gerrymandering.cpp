#include <bits/stdc++.h>
using namespace std;
#define int long long

int winner(int a, int b, int c) {
    return (a + b + c >= 2) ? 1 : 0;
}

void solve() {
    int n;
    cin >> n;

    vector<string> houses(2);
    cin >> houses[0] >> houses[1];

    vector<vector<int>> votes(2, vector<int>(n + 5, 0));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            votes[i][j + 1] = (houses[i][j] == 'A');
        }
    }

    vector<vector<int>> dp(n + 5, vector<int>(3, -1));

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (dp[i][j] == -1) {
                continue;
            }

            int cur = dp[i][j];

            if (j == 0) {
                if (i + 3 <= n) {
                    int add =   winner(votes[0][i + 1], votes[0][i + 2], votes[0][i + 3]) +
                                winner(votes[1][i + 1], votes[1][i + 2], votes[1][i + 3]);

                    dp[i + 3][0] = max(dp[i + 3][0], cur + add);
                }

                if (i + 2 <= n) {

                    int add = winner(votes[0][i + 1], votes[0][i + 2], votes[1][i + 1]);
                    dp[i + 1][1] = max(dp[i + 1][1], cur + add);

                    add = winner(votes[0][i + 1], votes[1][i + 1], votes  [1][i + 2]);
                    dp[i + 1][2] = max(dp[i + 1][2], cur + add);
                }
            } else if (j == 1) {
                if (i + 2 <= n) {

                    int add = winner(votes[1][i + 1], votes[1][i + 2], votes[0][i + 2]);

                    dp[i + 2][0] = max(dp[i + 2][0], cur + add);
                }

                if (i + 3 <= n) {
                    int add =   winner(votes[1][i + 1], votes[1][i + 2], votes[1][i + 3]) +
                                winner(votes[0][i + 2], votes[0][i + 3], votes[0][i + 4]);

                    dp[i + 3][1] = max(dp[i + 3][1], cur + add);
                }
            } else {
                if (i + 2 <= n) {
                    int add = winner(votes[0][i + 1], votes[0][i + 2], votes[1][i + 2]);

                    dp[i + 2][0] = max(dp[i + 2][0], cur + add);
                }

                if (i + 3 <= n) {

                    int add =   winner(votes[0][i + 1], votes[0][i + 2], votes[0][i + 3]) +
                                winner(votes[1][i + 2], votes[1][i + 3], votes[1][i + 4]);

                    dp[i + 3][2] = max(dp[i + 3][2], cur + add);
                }
            }
        }
    }

    cout << dp[n][0] << "\n";
    
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
    