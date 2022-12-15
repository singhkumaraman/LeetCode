//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 void DFS(int n, int m, vector<vector<char>>& mat,int x,int y){
       if(x<0 or y<0 or y>=m or  x>=n)return;    
       if(mat[x][y]=='X' or mat[x][y]=='V')return ;
        
       mat[x][y]='V';
       DFS(n,m,mat,x+1,y);
       DFS(n,m,mat,x-1,y);
       DFS(n,m,mat,x,y+1);
       DFS(n,m,mat,x,y-1);
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat)
    {
        // code here
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or i==n-1 or j==m-1){
                    if(mat[i][j]=='O')DFS(n,m,mat,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(mat[i][j]=='O')mat[i][j]='X';
              else if(mat[i][j]=='V')mat[i][j]='O';
            }
        }
        return mat;
    }
   
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends