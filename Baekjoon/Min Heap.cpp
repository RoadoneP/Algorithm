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

    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < n; i++)

    {

        int num;

        cin >> num;



        if (!num && pq.empty())

            cout << 0 << "\n";

        else if (!num)

        {

            cout << pq.top() << "\n";

            pq.pop();

        }

        else

            pq.push(num);

    }

    return 0;

}