#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 501

using namespace std;

int dp[MAX][MAX];
int cost[MAX];
int sum[MAX];//sum은 이전 cost들과의 합
int t;

int merge(int i, int j) {
    if (i == j)
        return 0;
    int& ret = dp[i][j];
    if (ret == -1) {
        for (int k = i; k <= j - 1; k++) {
            int temp = merge(i, k) + merge(k + 1, j) + sum[j] - sum[i - 1];
            if (ret == -1 || ret > temp)
                ret = temp;
        }
    }
    return ret;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            cin >> cost[i];
            sum[i] = cost[i] + sum[i - 1];
        }
        cout << merge(1, n) << endl;
    }
}