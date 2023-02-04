class Solution {
public:
    bool isValid(int n)
    {
        string s="";
        for (int i = 31; i >= 0; i--) 
        {
            int k = n >> i;
            if (k & 1)
                s+="1";
            else
                s+="0";
        }
        for(int i=0;i<31;i++)
        {
            if(s[i]=='1' and s[i+1]=='1')
            return false;
        }
        return true;
    }
    int findIntegers(int n) {
        vector<int> dpZero(32), dpOne(32), dp(32);
        dpZero[0] = dp[0] = 1;
        for (int i = 1; i < 32; ++i) {
            dpOne[i] = dpZero[i-1];
            dpZero[i] = dpZero[i-1] + dpOne[i-1];
            dp[i] = dpZero[i] + dpOne[i];
        }
        

        int sum=0;
        int last_seen=-1;
        for(int i=30;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(bit)
            {
                sum+=dp[i];
                if(last_seen==1)
                {
                    return sum;
                }
            }
            last_seen=bit;
        }
    return sum+1;
    }
};