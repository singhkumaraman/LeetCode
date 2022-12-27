//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int mod=1e5;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
     int n=arr.size();
     vector<int> distance(mod, 1e9);
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
     q.push({0, start});
     distance[start]=0;
     while (!q.empty())
     {
          int step = q.top().first;
          int node = q.top().second;
          if (node == end)
              return step;
          q.pop();
          for (int i = 0; i < n; i++)
          {
               int v = (node * arr[i]) % mod;
               if (distance[v] > step + 1)
               {
                    distance[v] = step + 1;
                    q.push({step + 1, v});
               }
          }
     }
     return distance[end]<1e9?distance[end]:-1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends