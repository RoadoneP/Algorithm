#include<bits/stdc++.h>
#define endl '\n'
#define MAX 50
using namespace std;



int main() {
	int m[2];
	cin >> m[0] >> m[1];
	sort(m, m + 1, greater<int>());
	int num;
	int gcf = 1; //최대공약수
	int lcm = m[0] * m[1]; //최소공배수
	while (1) {
		if (m[1] == 0) {
			gcf = m[0];
			break;
		}
		num = m[0] % m[1];
		m[0] = m[1];
		m[1] = num;
	}
	lcm = lcm / gcf;

	cout << gcf << endl << lcm;
}