class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        sort(nums.begin(), nums.end());

        int gcd = numsDivide[0];

        for (auto it : numsDivide)
        {
            gcd = __gcd(gcd, it);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (gcd % nums[i] == 0)
                return i;
        }
        return -1;
    }
};