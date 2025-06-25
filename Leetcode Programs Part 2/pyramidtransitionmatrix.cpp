class Solution {
public:
 vector<string> pyramid;
    unordered_set<string> used;
    unordered_map<int, string> blocks;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& pattern : allowed)
            blocks[blockHash(pattern[0], pattern[1])].push_back(pattern[2]);
        pyramid.push_back(bottom);
        for (int i = bottom.size() - 1; i > 0; i--)
            pyramid.push_back(string(i, ' '));
        return buildPyramid(0, 0);
    }
    bool buildPyramid(int levelIndex, int blockIndex) {
        if (pyramid[levelIndex].size() == 1)
            return true;
        if (blockIndex == pyramid[levelIndex].size() - 1) {
            if(used.count(pyramid[levelIndex+1]))
                return false;
            used.insert(pyramid[levelIndex+1]);
            return buildPyramid(levelIndex+1, 0);
        }
        for (char block : blocks[blockHash(pyramid[levelIndex][blockIndex], pyramid[levelIndex][blockIndex+1])]) {
            pyramid[levelIndex+1][blockIndex] = block;
            if (blockIndex > 0 && !blocks.count(blockHash(pyramid[levelIndex+1][blockIndex-1], pyramid[levelIndex+1][blockIndex])))
                continue;
            if (buildPyramid(levelIndex, blockIndex+1))
                return true;
        }
        return false;
    }
    int blockHash(char left, char right) {
        return (1 << letterId(left)) | (1 << (6 + letterId(right)));
    }
    char letterId(char c) {
        return c - 'A';        
    }
};
