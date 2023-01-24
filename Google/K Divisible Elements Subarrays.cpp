class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>s;

        for(int i=0;i<nums.size();i++)
        {
            vector<int>temp;
            int cnt=0;
            for(int j=i;j<nums.size();j++)
            {
                
                temp.push_back(nums[j]);
                if(nums[j]%p==0)
                cnt++;
                if(cnt>k)
                break;
                s.insert(temp);
            }
        }
        return s.size();
    }
};