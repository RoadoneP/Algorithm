#include<bits/stdc++.h>
#define endl '\n'
#define MAX 10001
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int a[MAX] = { 0, };
	int dp[MAX];
	int msum;


	for (int i = 1; i <= n; i++)
		cin >> a[i];

	dp[0] = a[0];
	dp[1] = max(a[0] + a[1], a[1]);
	dp[2] = max(a[2] + a[0], a[1] + a[2]);
	for (int i = 3; i <= n; i++) {
		dp[i] = max(a[i] + dp[i - 2], a[i] + a[i - 1] + dp[i - 3]);
		dp[i] = max(dp[i - 1], dp[i]);
	}
	msum = dp[0];
	for (int i = 1; i <= n; i++) {
		if (msum < dp[i])
			msum = dp[i];
		cout << dp[i] << ' ';
	}

	cout << msum;

}