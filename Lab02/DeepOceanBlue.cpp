/**
 * problem : Deep Ocean Blue
 * author  : tanapat namsomboon
 */
#include <bits/stdc++.h>

using namespace std;

// operation count
static int AdditionSubtraction = 0;
static int Multiplication = 0;
static int Division = 0;
static int Comparasion = 0;

void solve(int n, int p, int& sum)
{
    Comparasion++;
    if(n == 0) return;

    Comparasion++;
    if(p > 0)
    {
        sum *= n-1;
        p--;
        AdditionSubtraction+=2;
        Multiplication++;
    }
    else
    {
        sum *= n;
        Multiplication++;
    }
    AdditionSubtraction++;
    solve(n-1, p, sum);
}

int main()
{
    int n, v;
    cin >> n >> v;
    int temp;
    for(int i=0;i<n;i++) 
    {
        Comparasion++;
        cin >> temp;
        AdditionSubtraction++;
    }

    int p;
    cin >> p;
    for(int i=0;i<p;i++)
    {
        Comparasion++;
        cin >> temp;
        AdditionSubtraction++;
    }

    int sum = 1;
    solve(n, p, sum);
    cout << sum;
}