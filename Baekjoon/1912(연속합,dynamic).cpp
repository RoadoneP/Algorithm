#include<bits/stdc++.h>
#define endl '\n'
#define MAX 100001
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int dp[MAX];
	int n;
	int maxn;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> dp[i];
	}
	maxn = dp[0];
	for (int i = 1; i < n; i++)
	{
		if (dp[i] + dp[i - 1] > 0 && dp[i - 1] > 0)
			dp[i] = dp[i] + dp[i - 1];

		if (maxn < dp[i])
			maxn = dp[i];

	}
	cout << maxn;
}