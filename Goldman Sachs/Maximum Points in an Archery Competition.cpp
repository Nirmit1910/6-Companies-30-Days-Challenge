class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>ans(12,0);
        int score=0;
        for(int i=1;i<4096;i++)
        {
            int arr=numArrows;
            int b=0;
            vector<int>temp(12,0);
            for(int j=11;j>=0;j--)
            {
                if(i&(1<<j))
                {
                    if(aliceArrows[j]<arr)
                    {
                        temp[j]=aliceArrows[j]+1;
                        arr-=aliceArrows[j]+1;
                    }
                }
            }
            for(int j=0;j<12;j++)
            {
                if(i&(1<<j))
                {
                    temp[j]+=arr;
                    break;
                }
            }
            for(int j=0;j<12;j++)
            {
                if(temp[j]>aliceArrows[j])
                b+=j;
            }
            if(b>score)
            {
                score=b;
                ans=temp;
            }
        }
        return ans;
    }
};