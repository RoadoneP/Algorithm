#include<bits/stdc++.h>
#define endl '\n'
#define MAX 1000000007
#define ll long long

using namespace std;
ll result[2][2] = { 1,1,1,1 };

void Operator(ll a[][2], ll b[][2]) {

	int c[2][2];


	for (int i = 0; i < 2; i++) {
		memset(c[i], 0, sizeof(int) * 2);
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				c[i][j] += (a[i][k] * b[k][j])%MAX;
			}
			c[i][j] %= MAX;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = c[i][j];
		}
	}
}

int main() {
	int n;
	cin >> n;
	ll mat[2][2] = { 1,1,1,0 };
	int m = n - 1;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	while (m) {
		if (m % 2 == 1)
			Operator(result, mat);
		Operator(mat, mat);
		m /= 2;
	}
	cout << result[0][1];

}