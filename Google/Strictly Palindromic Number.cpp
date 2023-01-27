class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        string base;
        for(int i=2;i<=n-2;i++)
        {
            int temp=n;

            while(temp)
            {
                base+=to_string(temp%i);
                temp=temp/i;
            }

            int start=0,end=base.length()-1;

            while(start<=end)
            {
                if(base[start++]!=base[end--])
                return false;
            }
        }
        return true;
    }
};