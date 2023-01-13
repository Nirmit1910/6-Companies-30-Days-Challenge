class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>>m;

        for(int i=0;i<s.size();i++)
        {
            m[s[i]].push_back(i);
        }   
        int ans=0;

        for(int i=0;i<words.size();i++)
        {
            int pos=-1;
            for(int j=0;j<words[i].length();j++)
            {
                auto it=upper_bound(m[words[i][j]].begin(),m[words[i][j]].end(),pos);

                if(it==m[words[i][j]].end())
                break;
                pos=*it;
                if(j==words[i].length()-1)
                ans++;
            }   
        }
        return ans;
    }
};