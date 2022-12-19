//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0),Dvis(V,0);
        int flag=false;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                flag|=Dfs(i,adj,vis,Dvis);
            }
        }
        return flag;
    }
    bool Dfs(int src ,vector<int> adj[],vector<int>& vis,vector<int>& dfsVis){
     int flag=false;
     vis[src]=1;
     dfsVis[src]=1;
     for(int i:adj[src]){
         if(vis[i] and dfsVis[i])return true;
         if(vis[i])continue;
        flag|= Dfs(i,adj,vis,dfsVis);
     }
     dfsVis[src]=0;
     return flag;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends