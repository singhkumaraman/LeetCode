//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> vis(V+1,0);
        int ct=0;
        for(int v=0;v<V;v++){
            if(vis[v]==0){
                BFS(adj,v,vis);
                ct++;
            }
        }
        return ct;
    }
    void BFS(vector<vector<int>> adj, int V,vector<int>& vis){
        queue<int> Q;
        Q.push(V);
        vis[V]=1;
        while(!Q.empty()){
            int val=Q.front();
            Q.pop();
            for(int i=0;i<adj[val].size();i++){
                if(adj[val][i]==1){
                    if(vis[i]!=1){
                        Q.push(i);
                        vis[i]=1;
                    }
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends