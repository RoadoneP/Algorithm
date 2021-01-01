#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100
using namespace std;

ll Mat[MAX][MAX];
ll result[MAX][MAX];

void Operator(ll a[][MAX],ll b[][MAX],int n) {
	
	int c[MAX][MAX];
	

	for (int i = 0; i < MAX; i++) {
		memset(c[i], 0, sizeof(int) * MAX);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = c[i][j];
		}
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Mat[i][j];
		}
		result[i][i] = 1;
	}
	while (m) {
		if (m % 2 == 1)//지수가 홀수인경우
		{
			Operator(result, Mat, n);
		}
		Operator(Mat, Mat, n);
		m /= 2;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j]<< ' ';
		}
		cout << endl;
	}
	
}