class Allocator {
private:
    unordered_map<int, vector<pair<int, int>>> allocations;
    map<int, int> availableBlocks;
public:    
    Allocator(int n) { 
        availableBlocks.insert({0, n}); 
    }
    int allocate(int size, int mID) {
        for (auto allocIt = begin(availableBlocks); allocIt != end(availableBlocks); ++allocIt) {
            if (allocIt->second < size) {
                continue;
            }
            auto [startIndex, blockSize] = *allocIt;
            allocations[mID].push_back({startIndex, size});
            availableBlocks.erase(allocIt);
            if (blockSize > size) {
                availableBlocks.insert({startIndex + size, blockSize - size});
            }
            return startIndex;
        }
        return -1;
    }
    int freeMemory(int mID) {
        int freedSize = 0;
        auto allocIt = allocations.find(mID);
        if (allocIt == end(allocations)) {
            return 0;
        }
        for (auto [startIndex, size] : allocIt->second) {
            auto availIt = availableBlocks.insert({startIndex, size}).first;            
            if (availIt != availableBlocks.begin()) {
                auto prevIt = prev(availIt);
                auto& [prevStartIndex, prevBlockSize] = *prevIt;
                if (prevStartIndex + prevBlockSize == startIndex) {
                    prevBlockSize += size;
                    availableBlocks.erase(availIt);
                    availIt = prevIt;
                }
            }            
            if (availIt != availableBlocks.end()) {
                auto nextIt = next(availIt);
                auto [nextStartIndex, nextBlockSize] = *next(availIt);
                if (startIndex + size == nextStartIndex) {
                    availIt->second += nextBlockSize;
                    availableBlocks.erase(nextIt);
                }
            }            
            freedSize += size;
        }
        allocations.erase(allocIt);
        return freedSize;
    }
};
