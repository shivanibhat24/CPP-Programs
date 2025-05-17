class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        const int n = mountainArr.length();
        int low = 1, high = n - 2;
        while (low < high) {
            const int mid = (low + high) >> 1;
            const int v1 = mountainArr.get(mid);
            const int v2 = mountainArr.get(mid + 1);
            if (v1 < v2) {
                if (v1 == target)
                    return mid;
                if (v2 == target)
                    return mid + 1;
                low = mid + 1;
            } else
                high = mid;
        }

        const int targetIndex = getTargetIndex(target, mountainArr, 0, low, true);
        if (targetIndex != -1)
            return targetIndex;
        return getTargetIndex(target, mountainArr, low + 1, n - 1, false);
    }

private:
    int getTargetIndex(int target, MountainArray &mountainArr, int a, int b, bool increasing) const {
        while (a <= b) {
            const int mid = (a + b) >> 1;
            const int v = mountainArr.get(mid);

            if (v == target)
                return mid;

            if (increasing)
                if (v < target)
                    a = mid + 1;
                else
                    b = mid - 1;                    
            else
                if (v < target)
                    b = mid - 1;
                else
                    a = mid + 1;
        }
        return -1; 
    }
};
