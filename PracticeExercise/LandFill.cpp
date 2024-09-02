#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& x : v){
        cin >> x;
    }

    int l, m, r;
    cin >> l >> m >> r;

    vector<int> fill(2*m - l - r + 1);
    int id = 0;
    for(int i = l; i < m; i++)
        fill[id++] = i;   
    for(int i = m; i >= r; i--)
        fill[id++] = i;

    int len = n - fill.size() + 1;

    int min_rough = INT_MAX;
    for(int i=0; i<(1<<len); i++){
        vector<int> t(v.begin(), v.end());
        for(int j=0; j<len; j++){
            if(1<<j & i){
                for(int k = 0; k < (int)fill.size(); k++){
                    t[j+k] += fill[k];
                }
            }
        }
        
        int rough = 0;
        for(int j=0; j<n-1; j++){
            rough += abs(t[j] - t[j+1]);
        }
        min_rough = min(min_rough, rough);
    }

    cout << min_rough;
}