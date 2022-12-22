//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        //code here
        
    vector<int> adj[k];
     for (int i = 0; i < n - 1; i++)
     {
          int j = i + 1;
          for (int k = 0; k < min(dict[i].size(), dict[j].size()); k++)
          {
               if (dict[i][k] != dict[j][k])
               {
                    adj[dict[i][k] - 'a'].push_back(dict[j][k] - 'a');
                    break;
               }
          }
     }
     vector<int> inDeg(k, 0);
     for (int i = 0; i < k; i++)
     {
          for (auto j : adj[i])
          {
               inDeg[j]++;
          }
     }
     queue<int> bfs;
     for (int i = 0; i < k; i++)
     {
          if (inDeg[i] == 0)
               bfs.push(i);
     }
     vector<int> ans;
     while (!bfs.empty())
     {
          int val = bfs.front();
          bfs.pop();
          for (auto i : adj[val])
          {
               if (inDeg[i] > 0)
               {
                    inDeg[i]--;
                    if (inDeg[i] == 0)
                    {
                         bfs.push(i);
                    }
               }
          }
          ans.push_back(val);
     }
     string res="";
     for(int i=0;i<ans.size();i++){
          res+=(char)(ans[i]+'a');
     }
     return res;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends