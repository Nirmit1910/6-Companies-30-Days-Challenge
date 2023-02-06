class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();

        vector<vector<int>>dp(n,vector<int>(m,+1e9));

        return dfs(dungeon,0,0,dp,n,m);
        
    }
    int dfs(vector<vector<int>>& dungeon,int i,int j,vector<vector<int>>&dp,int n,int m)
    {
        if(i<0 || i>=n || j<0 || j>=m)
        return 1e9;

        if(i==n-1 and j==m-1)
        {
            if(dungeon[i][j]<=0)
            {
                return -dungeon[i][j]+1;
            }
            return 1;
        }

        if(dp[i][j]!=1e9)
        return dp[i][j];

        int a1=dfs(dungeon,i+1,j,dp,n,m);
        int a2=dfs(dungeon,i,j+1,dp,n,m);
        int minHealthRequired =  min(a1 , a2) -dungeon[i][j];
        
        dp[i][j] = ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;      
        return dp[i][j];
    }
};
