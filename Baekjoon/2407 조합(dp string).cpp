#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 102
#define INF 987654321
#define MOD 1000000

using namespace std;
int n, m;
string dp[MAX][MAX];

string bigNumAdd(string n1, string n2) {
    int sum = 0;
    string result;

    while (!n1.empty() || !n2.empty() || sum) {
        if (!n1.empty()) {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if (!n2.empty()) {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string comb(int n, int r) {
    if (n == r || r == 0) {
        return "1";
    }
    string& result = dp[n][r];

    if (result != "") {
        return result;
    }

    result = bigNumAdd(comb(n - 1, r - 1), comb(n - 1, r));
    return result;
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> m;

    cout<<comb(n, m);
   
}