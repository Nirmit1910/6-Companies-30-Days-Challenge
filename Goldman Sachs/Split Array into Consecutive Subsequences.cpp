class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>m;
        unordered_map<int,int>seq;
        for(auto i:nums)
        {
            m[i]++;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]])
            {
                if(seq[nums[i]])
                {
                    seq[nums[i]]--;
                    seq[nums[i]+1]++;
                }
                else
                {
                    if(m[nums[i]+1] and m[nums[i]+2])
                    {
                        m[nums[i]+1]--;
                        m[nums[i]+2]--;
                        seq[nums[i]+3]++;
                    }
                    else
                    {
                        return false;
                    }
                }
                m[nums[i]]--;
            }
        }
        return true;
    }
};