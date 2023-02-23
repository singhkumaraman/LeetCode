//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n+1,-1);
        return f(height,n,k,0,dp);
    }
    int f(vector<int>& height, int n, int k,int i, vector<int>& dp){
        if(i==n-1)return 0;
        int l=INT_MAX;
        if(dp[i]==-1){
        for(int j=1;j<=k;j++){
            if(i+j<n)
            l=min(l,f(height,n,k,i+j,dp)+abs(height[i]-height[i+j]));
        }
        dp[i]=l;
        }
        return dp[i];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends