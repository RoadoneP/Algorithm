#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 1001

using namespace std;
string str;

void solve() {
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (i % 2 == 0) {
			if (str[i] == 'a')
				str[i] = 'b';
			else
				str[i] = 'a';
		}
		else {
			if (str[i] == 'z')
				str[i] = 'y';
			else
				str[i] = 'z';
		}
	}
	cout << str << endl;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}