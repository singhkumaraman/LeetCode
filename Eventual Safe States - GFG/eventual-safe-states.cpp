//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0),dfsVis(V,0),ans;
       for(int i=0;i<V;i++){
           
           if(Cycle(i,adj,vis,dfsVis)==false)ans.push_back(i);
       }
       return ans;
        
    }
    bool Cycle(int V, vector<int> adj[],vector<int>& vis,vector<int>& dfsVis){
        if(vis[V] and dfsVis[V])return true;
        
        vis[V]=1;
        dfsVis[V]=1;
        for(int i:adj[V]){
           if(Cycle(i,adj,vis,dfsVis))return true;
        }
        dfsVis[V]=0;
        return false;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends