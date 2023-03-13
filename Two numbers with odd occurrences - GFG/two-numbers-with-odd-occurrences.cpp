//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        int a=0;
        for(int i=0;i<N;i++){
            a^=Arr[i];
        }
        int bit=0;
        for(int i=0;i<32;i++){
            if(a&(1<<i)){
                bit=i;break;
            }
        }
       long long int x1=0;
       long long int x2=0;
        for(int i=0;i<N;i++){
            if(Arr[i]&(1<<bit)){
                x1^=Arr[i];
            }
            else {
                x2^=Arr[i];
            }
        }
        vector<long long int> res;
        res.push_back(x1);
        res.push_back(x2);
        sort(res.rbegin(),res.rend());
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends