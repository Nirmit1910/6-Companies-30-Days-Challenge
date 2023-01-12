class Solution {
public:
    double dp[30][30][105];

    double knightProbability(int n, int k, int row, int column) {
        int dx[]={-2,-2,-1,-1,2,2,1,1};
        int dy[]={1,-1,2,-2,1,-1,2,-2};

        if(k==0)
        return 1;

        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(101,-1.0)));
        return dfs(n,n,row,column,k,dx,dy);
    }

    double dfs(int n,int m,int x,int y,int k,int dx[],int dy[])
    {
        if(x>=n || x<0 || y>=m || y<0)
        return 0;

        if(k==0)
        return 1;

        if(dp[x][y][k]!=0)
        return dp[x][y][k];

        

        double ans=0;
        for(int i=0;i<8;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
                
            ans+=dfs(n,m,xx,yy,k-1,dx,dy);
        }
        return dp[x][y][k]=ans/8.0;
    }
};