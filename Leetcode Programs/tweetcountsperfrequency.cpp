class TweetCounts {
private:   
unordered_map</*tweet*/string, map</*time*/int, /*count*/ int>> tweet_to_times_;
public:
    TweetCounts() {}
    void recordTweet(string tweetName, int time) {
        tweet_to_times_[tweetName][time]++;
    }
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName,
                                           int startTime, int endTime) {
            const int delta = [&](){
                if (freq == "minute") {
                    return 60;
                } else if (freq == "hour") {
                    return 3600;
                } else if (freq == "day") {
                    return 3600 * 24;
                } else {
                    assert (false);
                }
            }();
            const auto& tweet_times = tweet_to_times_[tweetName];
            auto cursor = tweet_times.lower_bound(startTime);
            vector<int> result = {0};
            while (cursor != tweet_times.end() && cursor->first <= endTime) {
                while (cursor->first >= startTime + delta) {
                    result.push_back(0);
                    startTime += delta;
                }
                result.back() += cursor->second;
                ++cursor;
            }
            while (startTime + delta <= endTime) {
                result.push_back(0);
                startTime += delta;
            }
            return result;
        }
};
