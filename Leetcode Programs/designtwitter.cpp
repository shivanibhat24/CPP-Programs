class Twitter {
private:
    int count;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;
public:
    Twitter() {
        this->count = 0;
    }    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({++count, tweetId});
    }    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        for (const auto& tweet : tweetMap[userId]) {
            maxHeap.push(tweet);
        }
        for (int followeeId : followMap[userId]) {
            for (const auto& tweet : tweetMap[followeeId]) {
                maxHeap.push(tweet);
            }
        }
        vector<int> result;
        int n = 0;
        while (!maxHeap.empty() && n < 10) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
            n++;
        }
        return result;
    }    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
