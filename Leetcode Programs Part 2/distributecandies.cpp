class Solution
{
public:
    int distributeCandies(vector<int>& candyType)
    {
        short counts[200001] { };
        int n = candyType.size();
        int distinct = 0;
        for (int i = 0; i < n; ++i)
            if (counts[candyType[i] + 100000]++ == 0)
                distinct++;
        return min(n / 2, distinct);
    }
};
