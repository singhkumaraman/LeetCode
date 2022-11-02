//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int fresh=0,t=0;
         queue<pair<int,int>> Q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    Q.push({i,j});
                }
                else if(grid[i][j]==1)fresh++;
            }
        }
         
       
        while(!Q.empty() and fresh>0){
            int sz=Q.size();
            for(int i=0;i<sz;i++){
            pair<int,int> val=Q.front();
            int row=val.first;
            int col=val.second;
            Q.pop();
            if(row>0 and grid[row-1][col]==1){
                grid[row-1][col]=2;
                Q.push({row-1,col});
                fresh--;
            }
            if(col>0 and grid[row][col-1]==1){
                grid[row][col-1]=2;
                Q.push({row,col-1});
                    fresh--;
            }
            if(row<n-1 and grid[row+1][col]==1){
                grid[row+1][col]=2;
                Q.push({row+1,col});
                    fresh--;
            }
            if(col<m-1 and grid[row][col+1]==1){
                grid[row][col+1]=2;
                Q.push({row,col+1});
                    fresh--;
            }
            }
              t++;
        }
        if(fresh==0)
        return t;
        return -1;

    }
    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends