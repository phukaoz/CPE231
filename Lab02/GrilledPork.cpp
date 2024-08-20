#include <bits/stdc++.h>

using namespace std;

// static int AdditionSubtraction = 0;
// static int Multiplication = 0;
// static int Division = 0;
// static int Comparasion = 0;

int main()
{
    vector<int> p(4);
    for(auto& x : p) cin >> x;

    int n;
    cin >> n;

    vector<bool> flag(n+1, 0);

    flag[0] = 1;
    for(auto x : p)
    {
        for(int i=x; i<=n; i++)
            flag[i] = flag[i] | flag[i-x];
    }

    for(int i=n; i>=0; i--)
    {
        if(!flag[i])
        {
            cout << i;
            break;
        }
    }
}