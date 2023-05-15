//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int i=0,j=0;
        int ans=0;
        while(i<n and j<n){
            if(nums[i]==0 and k>0){
                k--;i++;
            }
            else if(nums[i]==0 and k==0){
            while(j<n and  k==0){
                if(nums[j]==0)k++;
                j++;
            }
            }
            else if(nums[i]==1)i++;
            ans=max(i-j,ans);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends