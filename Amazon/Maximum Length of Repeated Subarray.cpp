class Solution {
public:
    int ans=0;
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans=max(ans,dp[i][j]);
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
    int f(vector<int>&nums1,vector<int>nums2,int n1,int n2,vector<vector<int>>&dp)
    {
        if(n1==-1 || n2==-1)
        return 0;

        if(dp[n1][n2]!=-1)
        return dp[n1][n2];

        if(nums[n1]==nums[n2])
        {
            dp[n1][n2]=1+f(nums1,nums2,n1+1,n2+1,dp);
            ans=max(ans,dp[n1][n2]);
        }
        else
        {
            dp[n1][n2]=0;
            ans=max(ans,f(nums1,nums2,n1+1,n2,dp));
            ans=max(ans,f(nums1,nums2,n1,n2+1,dp));
        }
        return dp[n1][n2];
    }
};