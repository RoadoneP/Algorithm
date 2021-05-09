#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 16
#define INF 987654321

using namespace std;

int n, m, k;
int dp[MAX][MAX];

pair<int, int> Pos;

void solution() {
    dp[1][1] = 1;
    if (k == 0)
    {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1];
            }
        }
        cout << dp[n][m] << endl;
    }
    else
    {
        for (int i = 1; i <= Pos.first; i++) {
            for (int j = 1; j <= Pos.second; j++) {
                dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1];
            }
        }
        int temp = dp[Pos.first][Pos.second];
        dp[Pos.first][Pos.second] = 1;

        for (int i = Pos.first; i <= n; i++) {
            for (int j = Pos.second; j <= m; j++) {
                if (i == Pos.first && j == Pos.second)
                    continue;
                dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1];
            }
        }
        cout << temp * dp[n][m] << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Pos.first = Pos.second = -1;

    cin >> n >> m >> k;

    int num = 1;
    if (k != 0) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (num == k) {
                    Pos.first = i;
                    Pos.second = j;
                }
                num++;
            }
        }
    }
    solution();
}