#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 1001

using namespace std;

int m, n;
int d[MAX][MAX];
int dp[MAX][MAX];

void solve() {
	int result = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = d[i][j];
			}
			else if (d[i][j] == 1) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]))+1;
			}
			result = max(dp[i][j], result);
		}
	}
	cout << (result*result) << endl;
}


int main() {

	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d",& d[i][j]);
		}
	}

	solve();
	
}