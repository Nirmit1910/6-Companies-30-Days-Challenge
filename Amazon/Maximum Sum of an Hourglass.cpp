class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>prefix(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)
                prefix[i][j]=grid[i][j];
                else
                prefix[i][j]=prefix[i][j-1]+grid[i][j];
                // cout<<prefix[i][j]<<" ";
            }
            // cout<<"\n";
        }
        int maxi=0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=2;j<m;j++)
            {
                int sum=prefix[i][j]+grid[i+1][j-1]+prefix[i+2][j];
                if(j-3>=0)
                sum=sum-prefix[i][j-3]-prefix[i+2][j-3];
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};