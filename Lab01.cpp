#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> p(n), t(n);
    for(auto &x : p) cin >> x;
    for(auto &x : t) cin >> x;

    sort(p.begin(), p.end());
    sort(t.begin(), t.end(), greater<int>());
    
    vector<int> pt(n);
    for(int i=0;i<n;i++)
        pt[i] = p[i] + t[i];

    sort(pt.begin(), pt.end());
    int res = 0;
    for(int i=0;i<n-1;i++)
        res += pt[i+1] - pt[i]; 
    
    cout << res;
}