//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> finishTime;
        vector<int> vis1(V,0),vis2(V,0);
        vector<int> revGraph[V];
        for(int i=0;i<V;i++){
            if(vis1[i]==0){
                dfs(i,vis1,finishTime,adj);
            }
        }
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                revGraph[it].push_back(i);
            }
        }
        vector<vector<int>> ans;
       while(finishTime.empty()==false){
       int i=finishTime.top();
       finishTime.pop();
            if(vis2[i]==0){
                vector<int> temp;
                DFS(i,vis2,revGraph,temp);
                ans.push_back(temp);
            }
        }
        return ans.size();
    }
    void dfs(int src,vector<int>& vis,stack<int>& st,vector<int> adj[]){
        if(vis[src]==1)return;
        vis[src]=1;
        for(int i:adj[src]){
            dfs(i,vis,st,adj);
        }
        st.push(src);
    }
    void DFS(int src,vector<int>& vis,vector<int> adj[],vector<int>&temp){
        if(vis[src]==1)return;
        vis[src]=1;
        temp.push_back(src);
        for(int i:adj[src]){
            DFS(i,vis,adj,temp);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends