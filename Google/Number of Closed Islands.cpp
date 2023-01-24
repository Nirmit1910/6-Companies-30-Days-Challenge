class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    if(dfs(grid,i,j))
                    cnt++;
                }
            }
        }
        return cnt;
    }
    bool dfs(vector<vector<int>>&grid,int x,int y)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
        {
            return false;
        }

        if(grid[x][y]==1)
        return true;
        grid[x][y]=1;

        bool d1 = dfs(grid, x+1, y);
        bool d2 = dfs(grid, x, y+1);
        bool d3 = dfs(grid, x-1, y);
        bool d4 = dfs(grid, x, y-1);
        return d1 && d2 && d3 && d4;
    }
};