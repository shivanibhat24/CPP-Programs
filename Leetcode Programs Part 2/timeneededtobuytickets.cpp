class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
    int time = 0;
    int need = tickets[k];   
    for (int i = 0; i < tickets.size(); i++) {
        if (i <= k)
            time += min(tickets[i], need);
        else
            time += min(tickets[i], need - 1);
    }
    return time;
}
};
