class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string>s;
        int len=text.length();
        for(int len=1;len<=text.length()/2;len++)
        {
            int cnt=0;
            for(int left=0,right=len;right<text.length();right++,left++)
            {
                if(text[left]==text[right])
                {
                    cnt++;
                }
                else
                {
                    cnt=0;
                }
                if(cnt==len)
                {
                    string str=text.substr(left,right-left+1);
                    s.insert(str);
                    cnt--;
                }
            }
        }
        return s.size();
    }
};