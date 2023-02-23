//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        return f(height,n,0,dp);
    }
    int f(vector<int>& height, int n,int i,vector<int>& dp){
     if(i==n-1)return 0;   
     if(dp[i]==-1){
     
     int l=f(height,n,i+1,dp)+abs(height[i]-height[i+1]);
     if(i+2<n)
     l=min(l,f(height,n,i+2,dp)+abs(height[i]-height[i+2]));
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends