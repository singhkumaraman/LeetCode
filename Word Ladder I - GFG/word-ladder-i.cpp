//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    
         int m = startWord.size();
         int n=wordList.size();
     unordered_set<string> list;
     for (int i = 0; i < n; i++)
     {
          list.insert(wordList[i]);
     }
     list.erase(startWord);
     queue<pair<string, int>> bfs;
     bfs.push({startWord, 1});
    //  int ans = INT_MAX;
     while (!bfs.empty())
     {
          pair<string, int> temp = bfs.front();
          string st = temp.first;
          int height = temp.second;
          bfs.pop();
          if(st==targetWord)return height;
        
          for (int i = 0; i < m; i++)
          {
               char c = st[i];
               for (int j = 0; j < 26; j++)
               {
                    st[i] = (char)(97 + j);
                    if (list.find(st) != list.end())
                    {
                         bfs.push({st, height + 1});
                         list.erase(st);
                    }
                    // if (st == targetWord)
                    //      ans = min(ans, height + 1);
               }
               st[i] = c;
          }
     }
    // return (ans!=INT_MAX?ans:0);
    return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends