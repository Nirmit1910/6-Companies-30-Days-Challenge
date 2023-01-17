class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int word=nums[0].length();

        vector<priority_queue<int>>v(nums.size());
        vector<int>ans;
        for(auto  it:queries)
        {
            int trim=it[1];
            int k=it[0];
            priority_queue<pair<string,int>>pq;
            for(int i=0;i<nums.size();i++)
            {
                string word=nums[i];

                word=word.substr(word.length()-trim,trim);

                if(pq.size()<k)
                {
                    pq.push({word,i});
                }
                else
                {
                    pair<string,int> p1={word,i};
                    if(p1<pq.top())
                    {
                        pq.pop();
                        pq.push({word,i});
                    }
                }
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};