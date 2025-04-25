class Solution {
public:
    double radius;
    double x_center; 
    double y_center;
    mt19937 gen{};
    std::uniform_real_distribution<> distribution{0, 1};          
    
    Solution(double radius, double x_center, double y_center) : radius{radius}, x_center{x_center}, y_center{y_center}
    {
    }
    static constexpr double two_pi = 2 * numbers::pi;
    const vector<double>& randPoint0() 
    {
        static vector<double> result = {0, 0};
        auto r = radius * sqrt(distribution(gen));
        auto theta = two_pi * distribution(gen); 
        result[0] = x_center + r * cos(theta);
        result[1] = y_center + r * sin(theta);
        return result;
    }
    const vector<double>& randPoint() 
    {
        static vector<double> result = {0, 0};
        auto sample = [](){ return 2.0 * ((double)rand()/RAND_MAX) - 1;};
        double x = sample();
        double y = sample();
        while( x*x + y*y > 1.0 )
        {
            x = sample();
            y = sample();
        }
        result[0] = x_center + x * radius;
        result[1] = y_center + y * radius;
        return result;
    }
};
