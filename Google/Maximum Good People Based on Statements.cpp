class Solution {
public:
    bool isValid(int curr,vector<vector<int>>& statements)
    {   
        int n=statements.size();
        for(int i=0;i<n;i++)
        {
            if(curr&(1<<(n-i-1)))
            {
                for(int j=0;j<n;j++)
                {
                    if(statements[i][j]!=2 and statements[i][j]!=bool(curr & 1 << (n-1-j)))
                    return false;
                }
            }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int ans=INT_MIN;
        int n=statements.size();
        for(int i=0;i<1<<n;i++)
        {
            if(isValid(i,statements))
            {
                ans=max(ans,__builtin_popcount(i));
            }
        }
        return ans;
    }
};