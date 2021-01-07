#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100001

using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	int n;
	vector<bool> v1, v2;

	while (t--) {
		cin >> n;
		int a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a == 1)
				v1.push_back(true);
			else
				v2.push_back(true);
		}
		if (v1.size() % 2 != 0)
			cout << "NO" << endl;
		else if (v1.size() % 2 == 0 && v2.size() % 2 == 0)
			cout << "YES" << endl;
		else
		{
			if (v1.size() >= 2 && v1.size() % 2 == 0)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		v1.clear();
		v2.clear();
	}

}