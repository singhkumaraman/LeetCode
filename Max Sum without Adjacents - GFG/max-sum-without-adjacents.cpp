//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n+1,-1);
	    return f(arr,n,0,dp);
	}
	int f(int *arr, int n,int i,vector<int>& dp){
	    if(i>=n){
	        return 0;
	    }
	    int l=INT_MIN;
	    if(dp[i]==-1){
	    l=f(arr,n,i+1,dp);
	    l=max(l,f(arr,n,i+2,dp)+arr[i]);
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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends