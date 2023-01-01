class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(ans,temp,1,0,k,n);
        return ans;
    }
    void f(vector<vector<int>>&ans,vector<int>&temp,int ind,int sum,int k,int n)
    {
        if(temp.size()==k)
        {
            if(sum==n)
            ans.push_back(temp);
            return;
        }
        if(sum>n)
        return ;
        for(int i=ind;i<=9;i++)
        {
            temp.push_back(i);
            f(ans,temp,i+1,sum+i,k,n);
            temp.pop_back();
        }
    }
};
