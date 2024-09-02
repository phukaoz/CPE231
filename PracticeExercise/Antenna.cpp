#include <bits/stdc++.h>

using namespace std;

struct tower{
    float a,b;
};

float cal(tower x, tower y){
    return abs(x.a - y.a)/(abs(x.a) + abs(y.a)) + abs(x.b - y.b)/(abs(x.b) + abs(y.b));
}

int main(){
    int n;
    cin >> n;

    vector<tower> v(n);
    for(auto& x : v){
        cin >> x.a >> x.b;
    }

    int min_tower = -1;
    float min_p = FLT_MAX;
    for(int i = 0; i < n; i++){
        float sum = 0;
        for(int j = 0; j < n; j++){
            sum += cal(v[i], v[j]);
        }
        if(sum < min_p){
            min_p = sum;
            min_tower = i;
        }
    }
    cout << v[min_tower].a << ' ' << v[min_tower].b;
}