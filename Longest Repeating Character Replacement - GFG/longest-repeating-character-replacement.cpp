//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int k) {
        // code here
        unordered_map<char,int> mapp;
        int n=S.size();
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            mapp[S[i]]++;
            int count=0;
            for(auto it:mapp){
                count=max(count,it.second);
            }
            if(i-j+1-count>k){
                mapp[S[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends