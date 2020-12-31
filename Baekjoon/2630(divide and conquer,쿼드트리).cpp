#include<bits/stdc++.h>
#define endl '\n'
#define MAX 128
using namespace std;

bool square[MAX][MAX];
int w_cnt = 0;
int b_cnt = 0;

void divide(int x, int y, int size) {
	int cnt = 0;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (square[i][j]) {
				cnt++;
			}
		}
	}
	if (!cnt)
		w_cnt++;
	else if (cnt == size * size)
		b_cnt++;
	else {
		divide(x, y, size / 2);
		divide(x, y + size / 2, size / 2);
		divide(x + size / 2, y, size / 2);
		divide(x + size / 2, y + size / 2, size / 2);
	}
	return;
}


int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> square[i][j];
	}
	divide(0, 0, n);
	cout << w_cnt << endl;
	cout << b_cnt;

}
