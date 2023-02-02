class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
        return i>=0 and i<n and j>=0 and j<m;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int,greater<int>>s;

        for(auto row:grid)
        {
            for(auto ele:row)
            {
                s.insert(ele);
            }
        }
        int n=grid.size();
        int m=grid[0].size();
        for(int sq=1;sq<=50;sq++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(isValid(i+sq,j+sq,n,m) and isValid(i-sq,j+sq,n,m) and isValid(i+sq,j-sq,n,m) and isValid(i-sq,j-sq,n,m))
                    {
                        int sum=0;
                        sum+=grid[i-sq][j]+grid[i+sq][j]+grid[i][j+sq]+grid[i][j-sq];
                        for(int diag=1;diag<sq;diag++)
                        {
                            sum+=grid[i-diag][j+sq-diag];
                        }
                        for(int diag=1;diag<sq;diag++)
                        {
                            sum+=grid[i-diag][j-sq+diag];
                        }
                        for(int diag=1;diag<sq;diag++)
                        {
                            sum+=grid[i+diag][j+sq-diag];
                        }
                        for(int diag=1;diag<sq;diag++)
                        {
                            sum+=grid[i+diag][j-sq+diag];
                        }
                        s.insert(sum);
                    }
                }
            }
        }
        vector<int>res;
        int c=0;
        for(auto it:s)
        {
            if(c==3)
            break;
            res.push_back(it);
            c++;
        }
        // reverse(res.begin(),res.end());
        return res;
    }
};