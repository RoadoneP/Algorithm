#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100
using namespace std;

int dp[21][21][21];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		//printf("w(%d,%d,%d) ", a, b, c);
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		//printf("w(%d,%d,%d) ", a, b, c);
		return w(20, 20, 20);
	}
	if (dp[a][b][c] != 0)
		return dp[a][b][c];
	else {
		if (a < b && b < c) {
			//printf("w(%d,%d,%d) ", a, b, c);
			dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		}
		else {
			//printf("w(%d,%d,%d) ", a, b, c);
			dp[a][b][c]= w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		}
		return dp[a][b][c];
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL);

	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
	}
}



