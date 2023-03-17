//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &v) {
        // code here
        int ten=0,fiv=0,tew=0;
        for(int i=0;i<N;i++){
            if(v[i]==5){
                fiv++;
            }
            else if(v[i]==10){
                if(fiv>0){
                    fiv--;
                    ten++;
                }
                else return false;
            }
            else {
                if(fiv>0 and ten>0){
                    tew++;
                    fiv--;
                    ten--;
                }
                else if(fiv>=3){
                    tew++;
                    fiv-=3;
                }
                else return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends