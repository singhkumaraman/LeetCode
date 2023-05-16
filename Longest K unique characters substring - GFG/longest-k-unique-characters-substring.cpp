//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int> mapp;
    int n=s.size();
    int j=0;
    int ans=-1;
    for(int i=0;i<n;i++){
        mapp[s[i]]++;
        if(mapp.size()>k){
          while(mapp.size()>k and j<n){
              mapp[s[j]]--;
              if(mapp[s[j]]==0)mapp.erase(s[j]);
              j++;
          }
        }
        else if(mapp.size()==k)
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends