#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, p;
    cin >> n >> p;

    map<string, int> mp;
    map<int, string> demp;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    vector<int> vertex;

    mp["THA"] = 0;
    demp[0] = "THA";

    int id = 1;
    for(int i=0;i<p;i++){
        string u, v;
        int w;
        cin >> u >> v >> w;
        if(mp.find(u) == mp.end()){
            mp[u] = id;
            vertex.push_back(id);
            demp[id++] = u;
        }
        if(mp.find(v) == mp.end()){
            mp[v] = id;
            vertex.push_back(id);
            demp[id++] = v;
        }
        
        graph[mp[u]][mp[v]] = w;
        graph[mp[v]][mp[u]] = w;
    }
    
    int mx = INT_MIN;
    vector<int> path;
    do {
        int cur = 0;

        int k = 0;
        for (int i=0; i<vertex.size(); i++) {
            cur += graph[k][vertex[i]];
            k = vertex[i];
        }
        cur += graph[k][0];

        if(cur > mx){
            mx = cur;
            path = vertex;
        }
    } while(next_permutation(vertex.begin(), vertex.end()));

    cout << "THA ";
    for(auto p : path){
        cout << demp[p] << ' ';
    }
    cout << "THA\n" << mx;
}