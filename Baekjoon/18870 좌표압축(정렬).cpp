#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 100001
#define INF 987654321

using namespace std;

bool comp(pair<pair<int, int>,int> a, pair<pair<int, int>,int> b) {
    return a.first.second < b.first.second;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int n;
    cin >> n;
    int inp;

    vector<pair<pair<int, int>,int>> v;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        v.push_back(make_pair(make_pair(inp, i),0));
    }
    sort(v.begin(), v.end());

    for (int i = 1; i < n; i++) {
        if (v[i].first.first == v[i - 1].first.first) {
            v[i].second = v[i - 1].second;
        }
        else
            v[i].second = v[i - 1].second + 1;
    }
    
    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < n; i++) {
        cout << v[i].second<<" ";
    }

}