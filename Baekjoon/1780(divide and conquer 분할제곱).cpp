#include<bits/stdc++.h>
#define endl '\n'
#define MAX 2400
#define ll long long
using namespace std;


ll power(ll a, ll b, ll c) {
	if (b == 0)
		return 0;
	if (b == 1)
		return a % c;
	ll tmp = power(a, b / 2, c) % c;
	ll result = (tmp * tmp) % c;
	if (b % 2 == 1)
		result = (result * a) % c;
	return result;
}


int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll a, b, c;

	cin >> a >> b >> c;

	cout << power(a, b, c);

}