class Solution {
public:
vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries)
{
    unordered_map<int, int> v;
    int n = s.length();
v.reserve(30*n);
    int got = 0;
    auto& v0 = v[0];
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0')
        {
            v0 = got ? v0 : i + ((i+1) << 16);
            got = true;
            continue;
        }
        int num = 0;
        int j = 0;
        for(; j < 30 && i+j < n; j++)
        {
            num = (num<<1) + (s[i+j] - '0');
            auto& vnum = v[num];
            vnum = vnum == 0 ? i + ((i+j+1) << 16) : vnum;
        }
    }
    for(int i = 0; i < queries.size(); i++)
    {
        auto it = v.find(queries[i][0] ^ queries[i][1]);
        queries[i][0] = it == v.end() ? -1 : it->second&0xffff;
        queries[i][1] = it == v.end() ? -1 : (it->second>>16)-1;
    }
    return queries;
}
};
