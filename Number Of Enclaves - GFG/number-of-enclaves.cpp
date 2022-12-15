//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or i==n-1 or j==m-1){
                    if(grid[i][j]==1)DFS(i,j,grid,n,m);
                }
            }
        }
        int ct=0;
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)ct++;
            }
        }
        return ct;
        
    }
    void DFS(int x,int y,vector<vector<int>> &grid,int n,int m){
        if(x<0 or y<0 or x>=n or y>=m)return;
        if(grid[x][y]==0)return ;
    
        grid[x][y]=0;
        
        DFS(x+1,y,grid,n,m);
        DFS(x-1,y,grid,n,m);
        DFS(x,y+1,grid,n,m);
        DFS(x,y-1,grid,n,m);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends