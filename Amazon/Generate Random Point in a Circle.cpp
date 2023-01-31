class Solution {
public:
    double r,x,y;
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x=x_center;
        y=y_center;
    }
    double random()
    {
        return double(rand())/RAND_MAX;
    }
    vector<double> randPoint() {
        double theta=2*3.14*random();
        double len=sqrt(random())*r;
        double xx=x+len*cos(theta);
        double yy=y+len*sin(theta);
        return {xx,yy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */