class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long neg=INT_MAX;

        int cnt=0;

        long long sum=0;

        for(auto i:matrix)
        {
            for(auto j:i)
            {
                sum+=abs(j);

                if(j<=0)
                cnt++;
                neg=min(neg,1LL*abs(j));
            }
        }
        if(cnt%2==0)
        return sum;

        return sum-2LL*neg;
    }
};