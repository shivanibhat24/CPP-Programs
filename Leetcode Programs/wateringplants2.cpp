class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int ans = 0;
        int lindex = 0;
        int rindex = plants.size()-1;
        int currentA = capacityA;
        int currentB = capacityB;
        while (lindex <= rindex) {
            if (lindex == rindex) {
                if (currentA == currentB) {
                    if (plants[lindex] <= currentA)
                        break;
                    else {
                        ans++;
                        break;
                    }
                } else if (currentA > currentB) {
                    if (plants[lindex] <= currentA)
                        break;
                    else {
                        ans++;
                        break;
                    }
                } else {
                    if (plants[lindex] <= currentB)
                        break;
                    else {
                        ans++;
                        break;
                    }
                }
            }
            if (currentA >= plants[lindex]) {
                currentA -= plants[lindex];
            } else if (plants[lindex] <= capacityA) {
                currentA = capacityA - plants[lindex];
                ans++;
            }
            if (currentB >= plants[rindex]) {
                currentB -= plants[rindex];
            } else if (plants[rindex] <= capacityB) {
                currentB = capacityB - plants[rindex];
                ans++;
            }
            lindex++;
            rindex--;
        }
        return ans;
    }
};
