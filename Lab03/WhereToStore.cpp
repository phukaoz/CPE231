#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    set<string> res;

    for(long long i = 0; i < (1LL<<n); i++){
        string sub = "";
        for(int j=0;j<n;j++){
            if(i & (1LL<<j)){
                sub += s[j];
            }
        }

        if(sub.length() > 1){
            string rev = sub;
            reverse(rev.begin(), rev.end());
            if(rev == sub){
                res.insert(sub);
            }
        }
    }

    cout << res.size();
}