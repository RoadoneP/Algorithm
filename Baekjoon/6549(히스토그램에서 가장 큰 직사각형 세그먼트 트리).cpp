#include<bits/stdc++.h>
#define endl '\n'
#define MAX 100001
#define ll long long

using namespace std;

//�ּ� ���̸� ���� ������ �ε����� ����
void init(vector<ll>&array, vector<ll>&tree, int node, int start, int end) {
	
	//start�� end�� ������ ���� ���. �̶� node�� start idx�� �ִ´�.
	if (start == end)
		tree[node] = start;
	//start�� end�� �ٸ����
	else
	{
		int mid = (start + end) / 2;
		init(array, tree, node * 2, start, mid);
		init(array, tree, node * 2+1, mid+1, end);
		//�������� ���� ���̰� ���� ���� ��忡 �ִ´�.
		if (array[tree[node * 2]] < array[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else
			tree[node] = tree[node * 2+1];
	}
}

//�������� ���� �ּ��� ������ ���� �ε��� ���ϱ�
int query(vector<ll>&array, vector<ll>&tree, int node, int start, int end,int i,int j) {
	
	if (end<i || start>j)
		return -1;
	else if (i <= start && end <= j)
		return tree[node];

	int mid = (start + end) / 2;
	int leftQuery = query(array, tree, node * 2, start, mid, i, j);
	int rightQuery = query(array, tree, node * 2+1, mid+1, end, i, j);

	if (leftQuery == -1)
		return rightQuery;
	else if (rightQuery == -1)
		return leftQuery;
	else if (array[leftQuery] < array[rightQuery])
		return leftQuery;
	else
		return rightQuery;

}
ll getMaxArea(vector<long long>& array, vector<long long>& tree, int start, int end) {
	
	int N = array.size() - 1;
	int idx = query(array, tree, 1, 1, N, start, end);

	ll area = (end - start + 1) * array[idx];

	//���� ���밡 �����ϴ°�
	if (start < idx) {
		ll temp = getMaxArea(array, tree, start, idx - 1);
		area = max(area, temp);
	}
	if (idx < end) {
		ll temp = getMaxArea(array, tree, idx + 1, end);
		area = max(area, temp);
	}
	return area;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		int N;
		cin >> N;
		if (N == 0)
			break;

		vector<ll> arr(N + 1);

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		int h = (int)ceil(log2(N));
		int tree_size = (1 << (h + 1));

		vector<ll>tree(tree_size);
		
		init(arr, tree, 1, 1, N);

		cout << getMaxArea(arr, tree, 1, N) << "\n";

	}
}