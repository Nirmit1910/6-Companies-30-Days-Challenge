class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefix(n+1,0);
        prefix[n]=0;
        prefix[0]=0;

        for(int i=1;i<=n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i-1];
        }

        stack<long long>st1,st2;

        vector<long long>right(n,0);
        vector<long long>left(n,0);


        st1.push(n-1);
        right[n-1]=n;
        for(int i=n-2;i>=0;i--)
        {
            while(!st1.empty() and nums[i]<=nums[st1.top()])
            {
                st1.pop();
            }
            if(st1.empty())
            {
                right[i]=n;
            }
            else
            {
                right[i]=st1.top();
            }
            st1.push(i);
        }
        left[0]=-1;
        st2.push(0);
        for(int i=1;i<n;i++)
        {
            while(!st2.empty() and nums[i]<=nums[st2.top()])
            {
                st2.pop();
            }
            if(st2.empty())
            {
                left[i]=-1;
            }
            else
            {
                left[i]=st2.top();
            }
            st2.push(i);
        }
        long long ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max((prefix[right[i]]-prefix[left[i]+1])*nums[i],ans);
        }
        int mod=1e9+7;
        return ans%mod;
    }
};