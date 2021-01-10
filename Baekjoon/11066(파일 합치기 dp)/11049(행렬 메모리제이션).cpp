#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 501
using namespace std;
int dp[MAX][MAX];
int arr[MAX][2] = { 0, };
int n;

int solve(int left, int right) {
    
    int& ret = dp[left][right];

    if (left == right)
        return 0;

    int minv = INT_MAX;
    if (ret != -1)
        return ret;
    
    for (int i = left; i < right; i++) {
        minv = min(minv, solve(left, i) + solve(i + 1, right) + (arr[left][0] * arr[i][1] * arr[right][1]));
    }
    ret = minv;
    return ret;

}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    cout << solve(0, n-1);

}