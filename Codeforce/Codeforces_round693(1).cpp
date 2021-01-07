#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100001

using namespace std;

int cnt = 0;

void divide(int w, int h) {

	if (w % 2 == 1 && h % 2 == 1) {
		cnt++;
		return;
	}

	else if (w % 2 == 0)
	{
		divide(w / 2, h);
		divide(w / 2, h);
	}
	else if (w % 2 == 1 && h % 2 == 0) {
		divide(w, h / 2);
		divide(w, h / 2);
	}

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	int w;
	int h;
	int n;
	cin >> t;
	while (t--) {

		cin >> w >> h >> n;

		divide(w, h);

		if (cnt >= n)
		{
			cout << "YES" << endl;

		}
		else {
			cout << "NO" << endl;
		}
		cnt = 0;
	}

}