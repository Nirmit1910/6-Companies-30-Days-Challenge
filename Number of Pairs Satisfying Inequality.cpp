class Solution {
public:
    long long validPairs(int l,int r,vector<long long>&nums,long long diff)
    {
        if(l==r)
        return 0;

        int m=(l+r)/2;

        long long result=validPairs(l,m,nums,diff)+validPairs(m+1,r,nums,diff);
        int l1 = l, r1 = m, l2 = m+1, r2 = r;
        vector<long long> merged;
        for(int j=l2;j<=r2;j++)
        {
            long long allowed=nums[j]+diff;

            long long ind=upper_bound(nums.begin()+l1,nums.begin()+r1+1,allowed)-nums.begin()-1;

            if(ind<=r1)
            result+=(ind-l1+1);
        }
        while (l1 <= r1 && l2 <= r2) {            
            if (nums[l1] <= nums[l2]) 
                merged.push_back(nums[l1 ++]);
            else 
                merged.push_back(nums[l2 ++]);
        }
        while (l2 <= r2) merged.push_back(nums[l2 ++]);
        while (l1 <= r1) merged.push_back(nums[l1 ++]);
        
        for (int j = l; j <= r; j ++) nums[j] = merged[j - l];
        return result;

    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        vector<long long>difference(n);

        for(int i=0;i<n;i++)
        {
            difference[i]=nums1[i]-nums2[i];
        }

        return validPairs (0, n-1, difference,diff );
        
    }
};