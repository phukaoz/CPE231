#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;
    int n = str.size();

    char a, b;
    cin >> a >> b;

    int p;
    cin >> p;

    // suff[i] = number of 'b' from i to n
    vector<int> suff(n+1);
    suff[n] = 0;
    for(int i = n-1;i>=0;i--){
        suff[i] = suff[i+1];
        if(str[i] == b){
            suff[i]++;
        }
    }

    int cnt = 0;
    for(int i=0;i<n-p+1;i++){
        if(str[i] == a){
            cnt += suff[i+p-1];
        }
    }

    cout << cnt;
}