#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 1000001
using namespace std;

int a[MAX] = { 0, };


int solution(int num) {
    if (num == 1 || a[num] != 0) return a[num];
    else {
        int max = MAX;

        if (num % 2 == 0) {
            max = min(solution(num / 2), max);
        }
        if (num % 3 == 0) {
            max = min(solution(num / 3), max);
        }
        if (solution(num - 1) < max) {
            max = a[num - 1];
        }

        return a[num] = max + 1;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    memset(a, 0, sizeof(a));
    cin >> n;

    cout << solution(n) << endl;

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}