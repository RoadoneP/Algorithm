#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 1001

using namespace std;
ll h_atk, h_hp, num_mon;
vector<pair<ll, ll>> mon;
ll fight,b;


void solve() {
	cin >> h_atk >> h_hp >> num_mon;

	mon.clear();
	mon.resize(num_mon);

	for (int i = 0; i < num_mon; i++) {
		cin >> mon[i].first;
	}
	for (int i = 0; i < num_mon; i++) {
		cin >> mon[i].second;
	}
	
	sort(mon.begin(), mon.end());

	for (int i = 0; i < num_mon; i++) {
		fight = (mon[i].second + h_atk - 1) / h_atk;
		h_hp -= mon[i].first * fight;
	}
	if (h_hp > 0)
		cout << "YES" << endl;
	else {
		h_hp += mon[num_mon - 1].first;
		if (h_hp > 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
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
