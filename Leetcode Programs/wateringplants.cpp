class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int i = -1, steps = 0, maxCap = capacity;
        int n = plants.size();
        while((i+1)<n)
        {
            if(maxCap >= plants[i+1])
            {
                maxCap -= plants[i+1];
                steps++;
                i++;
            }
            else
            {
                steps += 2*i + 2;
                maxCap = capacity;
            }
        }
        return steps;
    }
};
