class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j,int n,int m)
    {
        if(i<0 || i>=n || j<0 || j>=m)
        {
            return 0;
        }

        if(grid[i][j]!=1)
        return 0;

        int a=1;
        grid[i][j]=2;
        a+=dfs(grid,i+1,j,n,m);
        a+=dfs(grid,i,j+1,n,m);
        a+=dfs(grid,i-1,j,n,m);
        a+=dfs(grid,i,j-1,n,m);

        return a;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int ans=0;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans=max(ans,dfs(grid,i,j,n,m));
                }
            }
        }
        return ans;
    }
};