class Solution {
public:
    int N=1e7;
    vector<int>prime;
    vector<int> primes;
    void seive()
    {
        prime.resize(1000001,1);
        prime[0]=false,prime[1]=false;

        for(int i=2;i*i<=1000000;i++)
        {
          if(prime[i])
          {
            for (int j=i*i;j<=1000000;j+=i)
            {
              prime[j]=false;
            }
          }
        }
        // for(int i=2;i<=100000;i++)
        // {
        //   if(prime[i])
        //   primes.push_back(i);
        // }      
    }
    vector<int> closestPrimes(int left, int right) {
        seive();
        
        int n1=-1,n2=-1;
        int diff=INT_MAX;
        vector<int>ans(2,-1);
        for(int i=left;i<=right;i++)
        {
            if(prime[i])
            {
                if(n1==-1)
                {
                    n1=i;
                }
                else if(n2==-1)
                {
                    n2=i;
                }
                else
                {
                    if(abs(n1-n2)<diff)
                    {
                        diff=abs(n1-n2);
                        ans[0]=n1;
                        ans[1]=n2;
                    }
                    n1=n2;
                    n2=i;
                }
            }
        }
        if(abs(n1-n2)<diff)
        {
            diff=abs(n1-n2);
            ans[0]=n1;
            ans[1]=n2;
        }
        if(ans[0]==-1 || ans[1]==-1)
        return {-1,-1};
        return ans;
    }
};