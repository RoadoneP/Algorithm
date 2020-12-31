#include<bits/stdc++.h>
#define endl '\n'
#define MAX 1001
using namespace std;


int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {

		vector<pair<string, int>> v;
		int n;
		cin >> n;
		int res = 1;
		for (int i = 0; i < n; i++) {
			string name;
			string kind;
			bool dup = false;
			cin >> name >> kind;
			if (v.empty())
				v.push_back(make_pair(kind, 1));
			//같은종류인경우 
			else {
				for (int i = 0; i < v.size(); i++) {
					if (v[i].first == kind) {
						dup = true;
						v[i].second++;
					}
				}
				if (!dup)
					v.push_back(make_pair(kind, 1));
			}
		}
		for (int i = 0; i < v.size(); i++) {
			res *= (v[i].second + 1);
		}
		cout << res - 1 << endl;

		v.clear();
	}
	return 0;
}