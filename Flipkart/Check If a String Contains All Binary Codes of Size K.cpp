class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len=1<<k;

        int num=0;

        set<int>s1;
        for(int i=0;i<s.length();i++)
        {
            num=((num<<1)&((1<<k)-1))|(s[i]-'0');
            if(i-k>=-1)
            if(s1.find(num)==s1.end())
            s1.insert(num);

            if(s1.size()==len)
            return true;
        }
        return false;
    }
};
