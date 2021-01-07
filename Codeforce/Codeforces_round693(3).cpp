#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 1000001

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int>A(n);
		for (auto& Ai : A) cin >> Ai;

		vector<long long> ans(n, 0);

		for (int i = n - 1; i >= 0; i--) {
			if (i + A[i] >= n) {
				ans[i] = A[i];
			}
			else {
				ans[i] = A[i] + ans[i + A[i]];
			}
		}
		cout << *max_element(ans.begin(), ans.end()) << endl;
	}

}