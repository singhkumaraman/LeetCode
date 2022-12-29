//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,int>> Adj[V];
        // for(int i=0;i<adj[V].size();i++){
        //     Adj[adj[i][0]].push_back({adj[i][1],adj[i][2]});
        // }
        return MST_WT(adj,V);
       
    }
    int MST_WT(vector<vector<int>> GRAPH[], int v)
{
     // set<pair<int, int>> mst;
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
     // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
     vector<int> vis(v, 0);
     int sum = 0;
     q.push({0, 0});
     while (!q.empty())
     {
          auto temp = q.top();
          q.pop();
          int wt = temp.first;
          int node = temp.second;

          if (vis[node] == 0)
          {
               vis[node] = 1;
               sum += wt;
               for (auto i : GRAPH[node])
               {
                    if (vis[i[0]] == 0)
                         q.push({i[1], i[0]});
               }
          }
     }
     return sum;
}
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends