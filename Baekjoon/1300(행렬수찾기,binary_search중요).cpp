#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100001

using namespace std;

void binary(int n, int idx) {
	int left = 1;
	int right = idx;
	int result = -1;

	while (left<=right) 
	{
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 1; i <= n; i++) 
			cnt += min(mid / i, n); //mid보다 작은 j의 수(i*j<=mid)
		if (cnt < idx)
			left = mid + 1;
		else {
			result = mid;
			right = mid - 1;
		}
		
	}
	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, idx;
	cin >> n >> idx;
	
	binary(n, idx);
	
}