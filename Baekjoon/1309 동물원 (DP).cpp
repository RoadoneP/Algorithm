#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100001
#define INF 987654321
#define MOD 9901

using namespace std;

int n,ans;
int dp[MAX][3];

void solve() {
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i-1][1]) % MOD;
    }

    ans = (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;

    return;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    //0. n번째 줄에 사자가 없는 경우 
    //1. n번째 줄 왼쪽에 사자가 있는 경우, 
    //2. n번째줄 오른쪽에 사자가 있는경우.
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    solve();

    cout << ans << endl;
}