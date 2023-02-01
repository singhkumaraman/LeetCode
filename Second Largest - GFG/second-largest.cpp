//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int ans=INT_MIN;
	    unordered_set<int> sett;
	    for(int i=0;i<n;i++){
	        sett.insert(arr[i]);
	    }
	    int temp=INT_MIN;
	    for(int i:sett){
	        if(i>ans){
	            temp=ans;
	            ans=i;
	        }
	        else {
	            temp=max(temp,i);
	        }
	    }
	    return temp==INT_MIN?-1:temp;
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
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends