class Solution {
#define ll long long
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        ll ans = 0;
        vector<ll> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                   heights[i] < heights[st.top()])
                st.pop();
            int j = st.empty() ? -1 : st.top();
            left[i] = (j == -1 ? 0 : left[j]) + (ll)(i - j) * heights[i];
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() &&
                   heights[i] <
                       heights[st.top()])
                st.pop();
            int j = st.empty() ? n : st.top();
            right[i] = (j == n ? 0 : right[j]) + (ll)(j - i) * heights[i];
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, left[i] + right[i] - heights[i]);
        }
        return ans;
    }
};
