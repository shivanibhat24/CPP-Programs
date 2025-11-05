struct Count {
    int number, order, count;
    Count(int number, int order, int count) : number(number), order(order), count(count) {}
};

struct Compare1 {
    bool operator()(Count& c1, Count& c2) {
        if (c1.count != c2.count) {
            return c1.count > c2.count;
        }
        return c1.order > c2.order;
    }
};

struct Compare2 {
    bool operator()(Count& c1, Count& c2) {
        if (c1.count != c2.count) {
            return c1.count < c2.count;
        }
        return c1.order < c2.order;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& numbers, int k, int x) {
        int size_n = numbers.size();
        pair<int, int> numbers_sorted[size_n];
        for (int index = 0; index < size_n; index++) {
            numbers_sorted[index].first = index, numbers_sorted[index].second = numbers[index];
        }
        sort(&numbers_sorted[0], &numbers_sorted[0] + size_n, [&](pair<int, int>& n1, pair<int, int>& n2) {
            return n1.second < n2.second;
        });
        int orders[size_n];
        orders[numbers_sorted[0].first] = 0;
        int order = 0;
        for (int index = 1; index < size_n; index++) {
            order += (numbers_sorted[index - 1].second != numbers_sorted[index].second), orders[numbers_sorted[index].first] = order;
        }
        int size_c = order + 1;
        int counts[size_c];
        memset(&counts, 0, sizeof(counts));
        vector<bool> in_heap(order + 1, false);
        priority_queue<Count, vector<Count>, Compare1> heap1; // first = order, second = frequency
        priority_queue<Count, vector<Count>, Compare2> heap2; // first = order, second = frequency
        long long sum = 0ll;
        for (int index = 0; index < k; index++) {
            int number = numbers[index], order = orders[index];
            ++counts[order];
            if (in_heap[order]) {
                sum += static_cast<long long>(number), heap1.push({number, order, counts[order]});
            } else {
                heap2.push({number, order, counts[order]});
            }
            while (!heap1.empty() && (!in_heap[heap1.top().order] || counts[heap1.top().order] != heap1.top().count)) {
                heap1.pop();
            }
            while (!heap2.empty() && (in_heap[heap2.top().order] || counts[heap2.top().order] != heap2.top().count)) {
                heap2.pop();
            }
            if (heap2.empty()) {
                continue;
            }
            if (x > 0) {
                Count top2 = heap2.top();
                heap1.push(top2), in_heap[top2.order] = true, --x, sum += static_cast<long long>(top2.number) * static_cast<long long>(top2.count);
            } else {
                Count top1 = heap1.top(), top2 = heap2.top();
                if (top1.count < top2.count || (top1.count == top2.count && top1.order < top2.order)) {
                    heap1.pop(), heap1.push(top2), heap2.pop(), heap2.push(top1), in_heap[top1.order] = false, in_heap[top2.order] = true, sum = sum - static_cast<long long>(top1.number) * static_cast<long long>(top1.count) + static_cast<long long>(top2.number) * static_cast<long long>(top2.count);
                }
            }
        }
        int size_r = size_n - k + 1;
        vector<long long> result(size_r);
        result[0] = sum;
        for (int index = k; index < size_n; index++) {
            int number1 = numbers[index - k], order1 = orders[index - k], number2 = numbers[index], order2 = orders[index];
            if (number1 == number2) {
                result[index - k + 1] = sum;
                continue;
            }
            --counts[order1], ++counts[order2];
            if (in_heap[order1]) {
                sum -= static_cast<long long>(number1);
                if (counts[order1] != 0) {
                    heap1.push({number1, order1, counts[order1]});
                } else {
                    ++x, in_heap[order1] = false;
                }
            } else {
                heap2.push({number1, order1, counts[order1]});
            }
            if (in_heap[order2]) {
                sum += static_cast<long long>(number2), heap1.push({number2, order2, counts[order2]});
            } else {
                heap2.push({number2, order2, counts[order2]});
            }
            while (!heap1.empty() && (!in_heap[heap1.top().order] || counts[heap1.top().order] != heap1.top().count)) {
                heap1.pop();
            }
            while (!heap2.empty() && (in_heap[heap2.top().order] || counts[heap2.top().order] != heap2.top().count)) {
                heap2.pop();
            }
            if (heap2.empty()) {
                result[index - k + 1] = sum;
                continue;
            }
            if (x > 0) {
                Count top2 = heap2.top();
                heap1.push(top2), heap2.pop(), in_heap[top2.order] = true, --x, sum += static_cast<long long>(top2.number) * static_cast<long long>(top2.count);
            } else {
                Count top1 = heap1.top(), top2 = heap2.top();
                if (top1.count < top2.count || (top1.count == top2.count && top1.order < top2.order)) {
                    heap1.pop(), heap1.push(top2), heap2.pop(), heap2.push(top1), in_heap[top1.order] = false, in_heap[top2.order] = true, sum = sum - static_cast<long long>(top1.number) * static_cast<long long>(top1.count) + static_cast<long long>(top2.number) * static_cast<long long>(top2.count);
                }
            }
            result[index - k + 1] = sum;
        }
        return result;
    }
};
