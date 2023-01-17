class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>dp(n+1,0);

        dp[1]=1;
        long long peopleCanShare=0;
        int mod=1e9+7;
        for(int i=2;i<=n;i++)
        {
            if(i-delay>=0)
            {
                peopleCanShare=(peopleCanShare+dp[i-delay]+mod)%mod;
            }
            if(i-forget>=0)
            {
                peopleCanShare=(peopleCanShare-dp[i-forget]+mod)%mod;
            }
            dp[i]=peopleCanShare%mod;
        }
        long long ans=0;
        for(int i=n-forget+1;i<=n;i++)
        {
            ans=(ans+dp[i])%mod;
        }
        return (int)ans;       
    }
};