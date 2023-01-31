class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft=!left.size()?0:*max_element(left.begin(),left.end());
        int minRight=!right.size()?n:*min_element(right.begin(),right.end());

        return max(maxLeft,n-minRight);
    }
};