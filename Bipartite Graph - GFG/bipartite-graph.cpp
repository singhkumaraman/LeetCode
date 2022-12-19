//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>colors(V,-1);
	    for(int i=0;i<V;i++){
	        if(colors[i]==-1)
	        if(!check(i,adj,colors,0))return false;
	    }
	    return true;
	}
    bool check(int src,vector<int>adj[],vector<int> & colors,int color){
        
       colors[src]=color;
       for(int i:adj[src]){
           if(colors[i]==-1){
               if(!check(i,adj,colors,1-color))return false;
           }
           else if(color==colors[i]){
               return false;
           }
       }
       return true;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends