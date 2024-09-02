#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for(auto &x : v){
        cin >> x.first >> x.second;
    }
    vector<pair<int, int>> res;

    for(int i=0;i<n;i++){
        int mx = 0;
        for(int j=0;j<n-i;j++){
            if(v[j].second > v[mx].second){
                mx = j;
            }
        }

        res.push_back(v[mx]);
        v.erase(v.begin() + mx);
    }

    for(auto x : res){
        cout << x.first << '\n';
    }
}