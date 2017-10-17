#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<bool> used(n+1);
    used[1] = true;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        for(int i = 0; i < g[c].size(); i++){
            int n = g[c][i];
            if(!used[n]){
                used[n] = true;
                q.push(n);
            }
        }
    }
    bool c = true;
    for(int i = 1; i < n+1;i++){
        if(!used[i]){
            cout << i << endl;
            c = false;
        }
    }
    if(c) cout << "Connected" << endl;
}






