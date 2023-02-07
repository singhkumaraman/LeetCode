//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_set<int> stt;
      int s=INT_MAX,e=INT_MIN;
      for(int i=0;i<N;i++){
          s=min(arr[i],s);
          e=max(arr[i],e);
          stt.insert(arr[i]);
      }
      int ans=0,ct=0;
      for(int i=s;i<=e;i++){
          if(stt.find(i)!=stt.end()){
              ct++;
              ans=max(ct,ans);
          }
          else {
              ct=0;
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends