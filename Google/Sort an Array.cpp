class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        merge(nums,0,nums.size()-1);

        
        return nums;
    }

    void mergesort(vector<int>&nums,int lo,int mid,int hi)
    {
        int right=hi-mid;
        int left=mid+1-lo;

        vector<int>leftarray;
        vector<int>rightarray;

        for(int i=0;i<left;i++)
        {
            leftarray.push_back(nums[i+lo]);
        }
        for(int i=0;i<right;i++)
        {
            rightarray.push_back(nums[i+mid+1]);
        }
        int r=0,l=0,k=lo;
        while(r<right and l<left)
        {
            if(leftarray[l]<rightarray[r])
            {
                nums[k++]=leftarray[l++];
            }
            else
            {
                nums[k++]=rightarray[r++];
            }
        }

        while(r<right)
        {
            nums[k++]=rightarray[r++];
        }
        while(l<left)
        {
            nums[k++]=leftarray[l++];
        }
        return;
    }

    void merge(vector<int>&nums,int lo,int hi)
    {
        if(lo<hi)
        {
            int mid=lo+(hi-lo)/2;

            merge(nums,lo,mid);
            merge(nums,mid+1,hi);

            mergesort(nums,lo,mid,hi);
        }
    }
};