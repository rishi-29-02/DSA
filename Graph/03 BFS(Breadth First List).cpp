// Breadth First Traversal of a  undirected graph
// TC :: O(n + 2E)
// SC :: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]){
    vector<bool> vis(V+1, 0);
    vis[3] = 1;
    queue<int> q;
    q.push(3);
    
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> adj[n+1];
    
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> v = bfsOfGraph(n, adj);
    
    for(auto it:v) cout << it << " ";
    return 0;
}

// Starinting index 3 

// INPUT ::
// 6 5 
// 1 2
// 1 3
// 2 4 
// 2 5
// 5 6

// OUTPUT :: 
// 3 1 2 4 5 6 
