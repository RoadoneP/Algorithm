#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100001

using namespace std;
int a[MAX];

//재귀
void binary(int left, int right,int target) {
	int mid = (left + right) / 2;

	if (left > right && a[left] != target)
		cout << 0 << endl;
	else if (a[mid] == target) {
		cout << 1 << endl;
	}
	else
	{
		if (a[mid] < target) {
			binary(mid + 1, right, target);
		}
		else
			binary(left, mid-1, target);
	}

}
//반복문
void binary2(int n, int target) {
	int left = 0;
	int right = n;

	while (left < right) {
		int mid = (left + right) / 2;
		
		if (a[mid] == target) {
			cout << 1 << endl;
			return;
		}
		else {
			if (a[mid] < target) 
				left = mid + 1;
			else if (a[mid] > target) {
				right = mid - 1;
			}
		}
	}
	cout << 0 << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	int b[MAX];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a, a + n);
	cout << "재귀함수" << endl;
	for (int i = 0; i < m; i++) {
		binary(0,n, b[i]);
	}
	cout << "반복문" << endl;
	for (int i = 0; i < m; i++) {
		binary2(n, b[i]);
	}

}