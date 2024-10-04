#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int>& v, int n, int i){
    int k = i;
    int x = v[k];
    bool heap = false;
    while(!heap && (2*k + 1 < n)) {
        int j = 2*k + 1;
        if(j+1<n) {
            if(v[j] > v[j+1]) {
                j++;
            }
        }
        if(x <= v[j]) {
            heap = true;
        }else {
            v[k] = v[j];
            k = j;
        }
    }

    v[k] = x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }

    for(auto x : v){
        cout << x << ' ';
    }cout << '\n';

    for(int i = n-1; i > 0; i--) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }

    for(auto x : v){
        cout << x << ' ';
    }
}