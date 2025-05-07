class Solution {
public:
    int calPoints(vector<string>& operations) {
       std::vector<int> scores;
        for(auto& str : operations) {
            if(str == "C")
                scores.pop_back();
            else if(str == "D")
                scores.push_back(scores.back() * 2);
            else if(str == "+")
                scores.push_back(scores.back() + scores[scores.size() - 2]);
            else 
                scores.push_back(std::atoi(str.c_str()));
        }
        int sum = 0;
        for(int x : scores)
            sum += x;
        return sum;
    }
};
