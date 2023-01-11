class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int n=nums.size();
        vector<long>left(n,LONG_MIN);
        vector<long>right(n,LONG_MIN);

        getleft(nums,left);
        getright(nums,right);


        for(int i=0;i<n;i++)
        {
            if(left[i]!=LONG_MIN and right[i]!=LONG_MIN)
            return true;
        }
        return false;
    }
    void getleft(vector<int>&nums,vector<long>&left)
    {
        stack<int>st;
        st.push(nums[0]);

        for(int i=1;i<nums.size();i++)
        {
            while(!st.empty() and st.top()>=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                left[i]=st.top();
            }
            st.push(nums[i]);
        }
    }
    void getright(vector<int>&nums,vector<long>&right)
    {
        int n=nums.size();
        stack<int>st;
        st.push(nums[n-1]);
    
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                right[i]=st.top();
            }
            st.push(nums[i]);
        }
    }

};