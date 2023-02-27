//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return dfs(n,triangle,0,0,dp);
    }
    int dfs(int n, vector<vector<int>>& t,int r,int c, vector<vector<int>> &dp){
        if(r==n)return 0;
        if(dp[r][c]!=-1)return dp[r][c];
        
        return dp[r][c]=min(dfs(n,t,r+1,c,dp),dfs(n,t,r+1,c+1,dp))+t[r][c];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends