#include <span>
#include <vector>
using namespace std;

class TopVotedCandidate {

	vector<int>& times;
	vector<int> timelineTopVotedCandidates;

public:
	TopVotedCandidate(vector<int>& persons, vector<int>& times) :times{ times } {
		timelineTopVotedCandidates = createTimelineTopVotedCandidates(persons);
	}

	int q(int time) {
		int index = (upper_bound(this->times.begin(), this->times.end(), time))-1-times.begin();
       
		return timelineTopVotedCandidates[index];
	}

private:
	vector<int> createTimelineTopVotedCandidates(span<const int> persons) const {

		int topVotedCandidate = 0;
		int votesForTopVotedCandidate = 0;
		vector<int> votesPerCandidate(persons.size());
		vector<int> timelineTopVotedCandidates(persons.size());
		
		for (int i = 0; i < persons.size(); ++i) {

			++votesPerCandidate[persons[i]];
			if (votesForTopVotedCandidate <= votesPerCandidate[persons[i]]) {
				topVotedCandidate = persons[i];
				votesForTopVotedCandidate = votesPerCandidate[persons[i]];
			}
			timelineTopVotedCandidates[i] = topVotedCandidate;
		}
		return timelineTopVotedCandidates;
	}

	int searchForIndexUpperTimeBoundary(int time) const {
		int left = 0;
		int right = times.size() - 1;

		while (left <= right) {
			int middle = left + (right - left) / 2;

			if (times[middle] == time) {
				return middle;
			}

			if (times[middle] < time) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		return right;
	}
};
