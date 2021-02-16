#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1001
#define ll long long

using namespace std;

ll arr[MAX];
ll dp[101][21];
int n;
int cnt = 0;

ll solve(int len, int sum) {
    cnt++;
    if (sum < 0 || sum > 20)
        return 0;
    if (dp[len][sum] != -1)
        return dp[len][sum];
    if (len == n - 2) {
        if (sum == arr[n - 1])
            return 1;
        else
            return 0;
    }

    ll& ret = dp[len][sum];
    ret = 0;
    ret += solve(len + 1, sum + arr[len + 1]);
    ret += solve(len + 1, sum - arr[len + 1]);
    return ret;
}


int main(int argc, const char* argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));

    cout << solve(0,arr[0])<<endl;

    cout << "함수 호출 횟수: " << cnt << endl;
}