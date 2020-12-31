#include<bits/stdc++.h>
#define endl '\n'
#define MAX 10001
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, temp, cnt = 0;
	vector<int> v;

	v.push_back(INT_MIN);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp > v.back()) {
			v.push_back(temp);
			cnt++;
		}
		else {
			vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp);
			*low = temp;

		}
	}
	cout << cnt;


}