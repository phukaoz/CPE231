#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> v(n);
    int diff = INT_MAX;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(i > 0)
            diff = min(diff, v[i] - v[i-1]);
    }

    for(int i=0;i<n;i++)
        cout << v[i] - ( v[0] + ( i * diff) ) << ' ';

}