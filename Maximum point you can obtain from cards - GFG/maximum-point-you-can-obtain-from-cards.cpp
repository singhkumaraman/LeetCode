//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &v, int N, int k) {
        // code here
        vector<int> pre,pos;
        int n=v.size();
        int sum=0;
        pre.push_back(0);
        for(int i:v){
            sum+=i;
            pre.push_back(sum);
        }
        sum=0;
        for(int i=n-1;i>=0 ;i--){
            sum+=v[i];
            pos.push_back(sum);
        }
        reverse(pos.begin(),pos.end());
        pos.push_back(0);
        int j=0;
        if(n==k)return pre[n];
        int ans=pre[k];
        for(int i=0;i<n;i++){
            if(i-j+1==n-k){
                ans=max(ans,pos[i+1]+pre[j]);
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends