class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>v(n,vector<int>(m,0));


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 and j==0)
                v[i][j]=mat[i][j];
                else if(i==0)
                v[i][j]=v[i][j-1]+mat[i][j];
                else if(j==0)
                v[i][j]=v[i-1][j]+mat[i][j];
                else
                v[i][j]=v[i-1][j]+v[i][j-1]-v[i-1][j-1]+mat[i][j];
            }
        }
        vector<vector<int>>res(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x1 = max(0, i-k);
               int y1 = max(0, j-k);
               
               int x2 = min(i + k, n-1);
               int y2 = min(j + k, m-1);

               res[i][j]=v[x2][y2]-(x1>0?v[x1-1][y2]:0)-( y1 > 0 ? v[x2][y1-1] : 0 ) + ( (x1 > 0 && y1 > 0) ? v[x1-1][y1-1] : 0 );  
            }
        }
        return res;
    }
};