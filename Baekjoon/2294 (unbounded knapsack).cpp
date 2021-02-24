#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 101
#define INF 987654321

using namespace std;

int n, k;
int arr[101];
int dp[10001] = { 0, };


void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }
    if (dp[k] == 10001)
        cout << -1 << endl;
    else
        cout << dp[k] << endl;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        dp[i] = 10001;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    solve();

}