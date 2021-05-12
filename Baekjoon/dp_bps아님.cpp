#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 1001
#define INF 987654321

using namespace std;

int n, s, m;
vector<int> v;
int dp[101][MAX];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> m;
    dp[0][s] = 1;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX; j++) {
            if (dp[i][j] == 1) {
                if (dp[i + 1][j + v[i]] == 0 && j+v[i]<=m) {
                    dp[i + 1][j + v[i]] = 1;
                }
                if (dp[i + 1][j - v[i]] == 0 && j - v[i] >= 0) {
                    dp[i + 1][j - v[i]] = 1;
                }
            }
        }
    }

    int temp = -1;
    for (int i = 0; i < MAX; i++) {
        if (dp[n][i] == 1) {
            temp = i;
        }
    }
 
    cout << temp;

   
}