#include<bits/stdc++.h>
#define endl '\n'
#define MAX 1001
using namespace std;



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string a;
	int minus[MAX];
	memset(minus, 0, sizeof(minus));
	cin >> a;
	int n = 0;
	int idx = 0;
	int result;
	for (int i = 0; i < a.length(); i++) {
		if (a.at(i) == '+' || i == a.length() - 1) {
			minus[n] += (stoi(a.substr(idx, i)));
			idx = i + 1;
		}
		if (a.at(i) == '-') {
			minus[n] += (stoi(a.substr(idx, i)));
			n++;
			idx = i + 1;
		}
	}
	result = minus[0];
	for (int i = 1; minus[i] != 0; i++)
	{
		result -= minus[i];
	}
	cout << result;
}