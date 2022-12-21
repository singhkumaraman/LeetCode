//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int>adj[n];
        for(int i=0;i<m;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //kahns Algo
    vector<int> inDegree(n, 0), ans;
     queue<int> bfs;
     for (int i = 0; i < n; i++)
     {
          for (auto it : adj[i])
          {
               inDegree[it]++;
          }
     }
     for (int i = 0; i < n; i++)
     {
          if (inDegree[i] == 0)
               bfs.push(i);
     }
     while (!bfs.empty())
     {
          int val = bfs.front();
          bfs.pop();
          for (int i : adj[val])
          {
               if (inDegree[i] > 0)
               {
                    inDegree[i]--;
                    if (inDegree[i] == 0)
                         bfs.push(i);
               }
          }
          ans.push_back(val);
     }
     vector<int> filler;
      return ans.size()==n?ans:filler;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends