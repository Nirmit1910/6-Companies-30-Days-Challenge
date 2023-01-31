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
                char ch=words[i][j];
                auto it=upper_bound(m[ch].begin(),m[ch].end(),pos);

                if(it==m[ch].end())
                break;

                pos=*it;

                if(j==words[i].length()-1)
                ans++;
            }
        }
        return ans;
    }
};