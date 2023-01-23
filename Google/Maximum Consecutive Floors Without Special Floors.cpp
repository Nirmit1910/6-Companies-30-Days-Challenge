class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());


        int diff=INT_MIN;
        for(int i=0;i<special.size()-1;i++)
        {
            int first=special[i];
            int second=special[i+1];

            if(bottom>=first and bottom<=second and top>=first and top<=second)
            {
                diff=max(diff,bottom-first-1);
                diff=max(diff,top-bottom-1);
                diff=max(diff,second-top-1);
            }
            else if(bottom>=first and bottom<=second)
            {
                diff=max(diff,bottom-first-1);
                diff=max(diff,second-bottom-1);
            }
            else if(top>=first and top<=second)
            {
                diff=max(diff,top-first-1);
                diff=max(diff,second-top-1);
            }
            else if(bottom<=first and second<=top)
            {
                diff=max(diff,second-first-1);
            }
        }
        if(top>=special[special.size()-1])
        {
            diff=max(diff,top-special[special.size()-1]);
        }
        if(bottom<=special[0])
        {
            diff=max(diff,special[0]-bottom);
        }
        return diff;
    }
};