//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool canPlace(int n, vector<int> array, int dist, int cow)
{
     int count = cow - 1;
     int prev = array[0];
     for (int j = 1; j < n; j++)
     {
          if (array[j] - prev >= dist)
          {
               count--;
               prev = array[j];
          }
          if (count == 0)
               return true;
     }
     return false;
}
    int solve(int n, int k, vector<int> &stalls) {
    int ans=INT_MIN;
        // Write your code 
         sort(stalls.begin(), stalls.end());
         int s = 1;
          int e = stalls[n - 1] - stalls[0];
          while (s <= e)
          {
               int m = s + (e - s) / 2;
               if (canPlace(n, stalls, m, k))
               {
                    ans = max(ans, m);
                    s = m + 1;
               }
               else
                    e = m - 1;
          }
          return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends