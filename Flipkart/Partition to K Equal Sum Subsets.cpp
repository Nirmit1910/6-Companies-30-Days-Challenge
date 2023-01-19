class Solution {
public:

    bool solve(vector<int>&nums,int n,int i,int currSum,int sum,int k,vector<int>&taken)
    {
        if(k==1)
        return true;

        if(i==n)
        return false;

        if(currSum==sum)
        return solve(nums,n,0,0,sum,k-1,taken);


        for(int j=i;j<n;j++)
        {
            if(taken[j])
            {
                continue;
            }
            if(currSum+nums[j]<=sum)
            {
                taken[j]=1;
                if(solve(nums,n,j+1,currSum+nums[j],sum,k,taken))
                return true;

                taken[j]=0;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;

        for(auto x:nums)
        {
            sum+=x;
        }

        if(sum%k)
        return false;
        vector<int> taken(nums.size(), 0);
        return solve(nums,nums.size(),0,0,sum/k,k,taken);
    }
};