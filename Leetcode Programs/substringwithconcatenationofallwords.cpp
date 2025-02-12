class Solution {
public:
	struct matcher {
		struct info { int mtindex, count; };
		unordered_map<string_view, info>dict;
		int different_word_count;
		vector<int>slot;
		int maching_slot_count;
		matcher(const vector<string>& words) {
			int mtind = 0;
			for (auto& word : words) {
				auto find = dict.find(word);
				if (find != dict.end()) {
					++find->second.count;
				}
				else { dict[word] = { mtind++,1 }; }
			}
			different_word_count = mtind;
			slot = vector<int>(different_word_count, 0);
			maching_slot_count = 0;
		}
		void reset() {
			for (auto& i : slot) { i = 0; }
			maching_slot_count = 0;
		}
		bool match() {
			return maching_slot_count == different_word_count;
		}
		void push(string_view sv) {
			auto find = dict.find(sv);
			if (find == dict.end())return;
			if (++slot[find->second.mtindex] == find->second.count) {
				++maching_slot_count;
			}
		}
		void pop(string_view sv) {
			auto find = dict.find(sv);
			if (find == dict.end())return;
			if (--slot[find->second.mtindex] == find->second.count - 1) {
				--maching_slot_count;
			}
		}
	};
	vector<int> findSubstring(string s, const vector<string>& words) {
		int word_count = words.size();
		int word_len = words[0].size();
		matcher matcher(words);
		const char* str = s.c_str();
		int len = s.size();
		vector<int> ret;
		for (int off = 0; off < word_len; off++) {
			const char* beg = str + off, * end = str + len;
			if (beg + word_len * word_count <= end) {
				matcher.reset();
				for (int i = 0; i < word_count; i++) {
					string_view sv(beg + i * word_len, word_len);
					matcher.push(sv);
				}
				if (matcher.match()) {
					ret.push_back(beg - str);
				}
				const char* pos = beg + word_len * word_count;
				while (pos + word_len <= end) {
					string_view del(beg, word_len);
					string_view add(pos, word_len);
					beg += word_len;
					pos += word_len;
					matcher.pop(del);
					matcher.push(add);
					if (matcher.match()) {
						ret.push_back(beg - str);
					}
				}
			}
		}
		return ret;
	}
};
