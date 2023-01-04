class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        int i=1,len=0;
        while(i<n)
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                    len=lps[len-1];
            }
        }
        return s.substr(0,lps[s.size()-1]);
    }
};