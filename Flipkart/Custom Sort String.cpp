class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>f;

        for(auto it:s)
        {
            f[it]++;
        }
        string ans="";
        for(auto it:order)
        {
            if(f.find(it)!=f.end())
            {
                while(f[it])
                {
                    ans+=it;
                    f[it]--;
                }
            }
        }
        for(auto it:s)
        {
            if(f[it])
            {
                while(f[it])
                {
                    ans+=it;
                    f[it]--;
                }
            }
        }
        return ans;
    }
};