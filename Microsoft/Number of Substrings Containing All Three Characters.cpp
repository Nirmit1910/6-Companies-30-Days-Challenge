class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0,right=0;
        map<char,int>m;
        int ans=0;
        int n=s.size()-1;
        while(right<s.size())
        {
            m[s[right]]++;

            while(m['a'] and m['b'] and m['c'])
            {
                ans+=1+(n-right);
                m[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};