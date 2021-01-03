#include<bits/stdc++.h>
#define endl '\n'
#define MAX 100001
#define ll long long

using namespace std;

//최소 높이를 갖는 막대의 인덱스를 저장
void init(vector<ll>&array, vector<ll>&tree, int node, int start, int end) {
	
	//start와 end가 같으면 리프 노드. 이때 node에 start idx를 넣는다.
	if (start == end)
		tree[node] = start;
	//start와 end가 다른경우
	else
	{
		int mid = (start + end) / 2;
		init(array, tree, node * 2, start, mid);
		init(array, tree, node * 2+1, mid+1, end);
		//구간에서 가장 높이가 낮은 것을 노드에 넣는다.
		if (array[tree[node * 2]] < array[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else
			tree[node] = tree[node * 2+1];
	}
}

//구간에서 가장 최소인 높이의 막대 인덱스 구하기
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

	//왼쪽 막대가 존재하는가
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