#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 200001

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    int a;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (maxh.size() == minh.size())
            maxh.push(a);
        else
            minh.push(a);

        if (maxh.size() != 0 && minh.size() != 0 && maxh.top() > minh.top()) {
            int maxv = maxh.top();
            int minv = minh.top();
            maxh.pop();
            minh.pop();
            maxh.push(minv);
            minh.push(maxv);
        }
        cout << maxh.top() << endl;
    }

}