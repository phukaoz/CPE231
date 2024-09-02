#include <iostream>
#include <vector>

using namespace std;

struct t{
    long long way = 0;
    long long odd = 0;
    long long even = 0;
};

int main(){
    int x, y;
    cin >> x >> y;

    vector<t> dp(y+1);

    dp[0] = {1};
    for(int i=1;i<=x;i++){
        for(int j=y;j>=i;j--){
            if(dp[j-i].way){
                dp[j].way += dp[j-i].way;
                dp[j].odd += dp[j-i].odd + ((i&1) * dp[j-i].way);
                dp[j].even += dp[j-i].even + (!(i&1) * dp[j-i].way);
            }
        }
    }
    
    cout << dp[y].odd << '\n' << dp[y].even;
}