class Solution {
   public:
	int minimumIndex(vector<int>& nums) {
		int cnt = 0;
		int dom_num = 0;

		for (int num : nums) {
			if (cnt == 0) {
				dom_num = num;
			}
			if (dom_num == num) {
				cnt++;
			} else {
				cnt--;
			}
		}

		int n = nums.size();
		int total = count(nums.begin(), nums.end(), dom_num);

		if (n == total * 2 - 1) {
			return -1;
		}

		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (nums[i] == dom_num) {
				cnt++;
			}

			if (cnt * 2 > i + 1 && (total - cnt) * 2 > n - i - 1) {
				return i;
			}
		}

		return -1;
	}
};
