//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e9+7;
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        if(grid[0][0]==1)return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return dfs(n,m,grid,0,0,dp);
    }
    int dfs(int n, int m, vector<vector<int>>& grid,int x,int y,vector<vector<int>>& dp){
        
        if(x==n-1 and y==m-1)return 1;
        if(x>=n or y>=m)return 0;
        if(grid[x][y]==1)return 0;
        if(dp[x][y]!=-1)return dp[x][y];
        return dp[x][y]=((dfs(n,m,grid,x+1,y,dp)%mod)+(dfs(n,m,grid,x,y+1,dp)%mod))%mod;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends