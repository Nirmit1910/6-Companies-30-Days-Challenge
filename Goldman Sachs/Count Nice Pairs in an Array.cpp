class Solution {
public:
    long getReverse(int nums)
    {
        long rev=0;
        while(nums)
        {
            rev=rev*10+nums%10;
            nums=nums/10;
        }
        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<long,long>difference;

        for(int i=0;i<nums.size();i++)
        {
            long rev=getReverse(nums[i]);
            long sum=nums[i]-rev;
            // cout<<sum<<" ";
            difference[sum]++;
        }
        int ans=0;
        int MOD=1e9+7;
        for(auto it:difference)
        {
            // cout<<it.first<<" ";
            long mul=((it.second*(it.second-1))/2)%MOD;
            ans+=mul;
        }
        
        return ans%MOD;
    }
};