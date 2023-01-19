class Solution {
    
public:
    int f(int n,int k)
    {
        if(n==1)
            return 0;
        int x=f(n-1,k);
        int y=(x+k)%n;
        
        return y;
    }
    
public:
    int findTheWinner(int n, int k) {
        int x=f(n,k);
        return x+1;
    }
};