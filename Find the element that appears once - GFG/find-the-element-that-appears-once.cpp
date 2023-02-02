//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
int search(int A[], int N)
{
     int s = 0, e = N - 1;
     while (s <= e)
     {
          int m = s + (e - s) / 2;
          if ( A[m] != A[m + 1] and A[m] != A[m - 1] or m==0)
               return A[m];
          else if (m % 2 == 0)
          {
               if (A[m] == A[m + 1])
               {
                    s = m + 1;
               }
               else if (A[m] == A[m - 1])
               {
                    e = m - 1;
               }
          }
          else
          {
               if (A[m] == A[m + 1])
               {
                    e = m - 1;
               }
               else if ( A[m] == A[m - 1])
               {
                    s = m + 1;
               }
          }
     }
     return -1;
}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends