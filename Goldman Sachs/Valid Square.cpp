class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int>s;

        s.insert(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2));
        s.insert(pow(p2[0]-p3[0],2)+pow(p2[1]-p3[1],2));
        s.insert(pow(p3[0]-p4[0],2)+pow(p3[1]-p4[1],2));
        s.insert(pow(p4[0]-p1[0],2)+pow(p4[1]-p1[1],2));
        s.insert(pow(p1[0]-p3[0],2)+pow(p1[1]-p3[1],2));
        s.insert(pow(p2[0]-p4[0],2)+pow(p2[1]-p4[1],2));

        return !s.count(0) and s.size()==2;
    }
};