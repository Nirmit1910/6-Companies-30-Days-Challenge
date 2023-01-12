class Solution {
public:
    int magicalString(int n) {
        vector<int>str;
        str.push_back(1);
        str.push_back(2);
        str.push_back(2);

        if(n==0)
        return 0;

        if(n<=3)
        {
            return 1;
        }

        if(n==4)
        return 2;

        int idx=2;
        int digit=1;
        while(str.size()<n)
        {
            if(str[idx]==2)
            {
                str.push_back(digit);
                str.push_back(digit);
            }
            if(str[idx]==1)
            {
                str.push_back(digit);
            }
            if(digit==1)
            digit=2;
            else
            digit=1;

            idx++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]==1)
            ans++;
        }
        return ans;
    }
};