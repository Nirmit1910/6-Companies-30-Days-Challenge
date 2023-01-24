class Solution {
public:
    vector<int>weight;
    Solution(vector<int>& w) {
        for(auto it:w)
        {
            if(weight.size())
            {
                weight.push_back(it+weight.back());
            }
            else
            {
                weight.push_back(it);
            }
        }
    }
    
    int pickIndex() {
        int x = weight.back();
        int index = rand() % x;
        auto it = upper_bound(weight.begin(), weight.end(),index);
        return it - weight.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */