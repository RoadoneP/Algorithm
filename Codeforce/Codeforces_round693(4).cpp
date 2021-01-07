#include<bits/stdc++.h>
#define endl '\n'
#define ll long long


const ll MAX = 1e6;
using namespace std;

ll n;
ll a[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while(T--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a, a + n);
		reverse(a, a + n);

		ll s = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				if (a[i] % 2 == 0) s += a[i];
			}
			else {
				if (a[i] % 2 == 1) s -= +a[i];
			}
		}
		if (s > 0) cout << "Alice\n";
		else if (s < 0) cout << "Bob\n";
		else cout << "Tie\n";
	}
	memset(a, 0, sizeof(int)*n);	
}