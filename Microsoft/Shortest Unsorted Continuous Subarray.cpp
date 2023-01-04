class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int lo=-1,hi=-1;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                lo=i;
                break;
            }
        }
        for(int i=n-1;i>=1;i--)
        {
            if(nums[i-1]>nums[i])
            {
                hi=i;
                break;
            }
        }
        cout<<"lo="<<lo<<" hi="<<hi<<"\n";

        if(lo==-1 and hi==-1)
        return 0;
        int mini=nums[lo],maxi=nums[hi];
        for(int i=lo;i<=hi;i++)
        {
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        cout<<"mini="<<mini<<" "<<"maxi="<<maxi;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>mini)
            {
                lo=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<maxi)
            {
                hi=i;
                break;
            }
        }
        return hi-lo+1;

    }
};