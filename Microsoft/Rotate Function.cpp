class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        vector<int>dp(nums.size(),0);

        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            dp[0]+=i*nums[i];
            sum+=nums[i];
        }
        long long maxi=dp[0];
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=dp[i-1]+sum-(nums.size())*nums[nums.size()-i];
            maxi=max(maxi,1LL*dp[i]);
        }
        return maxi;
    }
};