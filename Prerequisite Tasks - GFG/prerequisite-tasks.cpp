//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[N];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        //kahns Algo
    vector<int> inDegree(N), ans;
     queue<int> bfs;
     for (int i = 0; i < N; i++)
     {
          for (auto it : adj[i])
          {
               inDegree[it]++;
          }
     }
     for (int i = 0; i < N; i++)
     {
          if (inDegree[i] == 0)
               bfs.push(i);
     }
     while (!bfs.empty())
     {
          int val = bfs.front();
          bfs.pop();
          for (int i : adj[val])
          {
               if (inDegree[i] > 0)
               {
                    inDegree[i]--;
                    if (inDegree[i] == 0)
                         bfs.push(i);
               }
          }
          ans.push_back(val);
     }
       return ans.size()==N?true:false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends