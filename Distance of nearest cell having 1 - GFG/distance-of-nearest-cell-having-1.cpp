//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    vector<vector<int>> dis(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>>bfsQ;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                bfsQ.push({{i,j},0});
	            }
	        }
	    }
	    
	    while(!bfsQ.empty()){
	        pair<pair<int,int>,int> cell=bfsQ.front();
	        bfsQ.pop();
	        int row=cell.first.first;
	        int col=cell.first.second;
	        int dist=cell.second;
	        dis[row][col]=dist;
	        
	        if(row-1>=0 and grid[row-1][col]==0 and vis[row-1][col]!=1){
	            grid[row-1][col]=-1;
	            bfsQ.push({{row-1,col},dist+1});
	            vis[row-1][col]=1;
	        }
	         if(row+1<n and grid[row+1][col]==0 and vis[row+1][col]!=1){
	            grid[row+1][col]=-1;
	            bfsQ.push({{row+1,col},dist+1});
	            vis[row+1][col]=1;
	        }
	         if(col-1>=0 and grid[row][col-1]==0 and vis[row][col-1]!=1){
	            grid[row][col-1]=-1;
	            bfsQ.push({{row,col-1},dist+1});
	            vis[row][col-1]=1;
	        }
	         if(col+1<m and grid[row][col+1]==0 and vis[row][col+1]!=1){
	            grid[row][col+1]=-1;
	            bfsQ.push({{row,col+1},dist+1});
	            vis[row][col+1]=1;
	        }
	    }
	    return dis;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends