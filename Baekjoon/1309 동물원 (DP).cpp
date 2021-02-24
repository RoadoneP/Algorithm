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
    //0. n��° �ٿ� ���ڰ� ���� ��� 
    //1. n��° �� ���ʿ� ���ڰ� �ִ� ���, 
    //2. n��°�� �����ʿ� ���ڰ� �ִ°��.
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    solve();

    cout << ans << endl;
}