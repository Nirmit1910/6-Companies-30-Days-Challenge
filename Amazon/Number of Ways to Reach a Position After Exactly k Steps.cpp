class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        // vector<vector<vector<int>>>dp(1001,vector<vector<int>>(1001,vector<int>(1001,-1)));
        vector<vector<int>>dp(4001,vector<int>(1001,-1));
        // memset(dp,sizeof(dp),-1);
        startPos+=2000;
        endPos+=2000;
        return f(dp,startPos,endPos,k);
    }
    int f(vector<vector<int>>&dp,int start,int end,int k)
    {
        if(k==0)
        {
            if(start==end)
            return 1;
            else
            return 0;
        }
        if(k<=0)
            return 0;
        if(dp[start][k]!=-1)
        return dp[start][k];


        int ans=0;
        
        ans+=f(dp,start+1,end,k-1);

        ans+=f(dp,start-1,end,k-1);
        return dp[start][k]=ans%1000000007;
    }
};