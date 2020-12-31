#include<bits/stdc++.h>
#define endl '\n'
#define MAX 2400
using namespace std;

int square[MAX][MAX];
int zero_cnt = 0;
int one_cnt = 0;
int minus_cnt = 0;

void divide(int x, int y, int size) {

	if (size == 1) {

		if (square[x][y] == 1)
			one_cnt++;
		else
			zero_cnt++;
		return;
	}
	for (int i = x; i < x + size; i++) {
		for (int j = y + 1; j < y + size; j++) {
			if (square[x][y] != square[i][j]) {
				for (int a = 0; a < 2; a++) {
					for (int b = 0; b < 2; b++) {
						divide(x + (size / 2) * a, y + (size / 2) * b, size / 2);
					}
				}
				return;
			}
		}
	}
	if (square[x][y] == 1)
		one_cnt++;
	else
		zero_cnt++;
	return;
}


int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> square[i][j];
		}
	}
	divide(0, 0, n);
	cout << minus_cnt << endl;
	cout << zero_cnt << endl;
	cout << one_cnt;
}