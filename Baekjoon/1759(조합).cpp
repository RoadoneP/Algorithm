#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 50

using namespace std;

vector<char> v;
vector<int> pick;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char p;

    int L, C;

    cin >> L >> C;
   
    for (int i = 0; i < C; i++) {
        cin >> p;
        v.push_back(p);
        pick.push_back(1);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < L; i++) {
        pick[i] = 0;
    }
    //조합
    do {
        string password = "";
        for (int i = 0; i < C; i++) {
            if (pick[i] == 0) {
                password += v[i];
            }
        }
        int cnt1 = 0; //모음 카운트
        int cnt2 = 0; //자음 카운트
        for (int i = 0; i < password.size(); i++) {
            if (password[i] == 'a' || password[i] == 'e'
                || password[i] == 'i' || password[i] == 'o'
                || password[i] == 'u')
                cnt1++;
            else
                cnt2++;
        }
        if (cnt1 < 1 || cnt2 < 2)
            continue;
        cout << password << '\n';
    } while (next_permutation(pick.begin(), pick.end()));
     
}