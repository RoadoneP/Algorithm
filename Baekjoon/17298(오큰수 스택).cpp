#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 1000

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, temp;
	vector<int>v;
	stack<int>s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	vector<int> ans(v.size(), -1);
	
	//ó������ s.top���� �ٷ� �����ʼ��� ū�� Ȯ��
	//example 3 5 2 7 ���
	for (int i = 0; i < v.size(); i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			ans[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';


}