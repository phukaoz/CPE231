#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> perm(n);
    vector<vector<float>> v(n, vector<float>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }
    iota(perm.begin(), perm.end(), 0);
    float mx = FLT_MIN; 
    do{
        float cur = 0;

        for(int i=0;i<n;i++){
            cur += v[i][perm[i]];
        }

        mx = max(cur, mx);
    }while(next_permutation(perm.begin(), perm.end()));

    cout << mx;
}