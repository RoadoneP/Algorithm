/*�丣���� �������� �̿��� ���װ��*/

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll MOD = 1000000007; //#define���� �ϸ� �ȵ�

ll pow(ll num, ll idx) // B^p-2 �ִ´�
{
	if (idx == 0)
		return 1;
	else if (idx == 1)
		return num;
	if (idx % 2 == 0) {
		ll temp = pow(num, idx / 2) % MOD;
		return (temp * temp) % MOD;
	}
	ll temp = pow(num, idx - 1) % MOD;
	return (num * temp) % MOD;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	ll n, k;

	cin >> n >> k;
	ll up = 1, down = 1, result;
	//up�� n! down�� (n-k)!k!

	for (int i = 2; i <= n; i++) {
		up *= i;
		up %= MOD;
	}
	for (int i = 1; i <= n-k; i++) {
		down *= i;
		down %= MOD;
	}
	for (int i = 1; i <= k; i++) {
		down *= i;
		down %= MOD;
	}
	
	result = up * pow(down, MOD - 2); // (A/B)%p== A%p * B^p-2%p �� ����

	cout << result % MOD;
}