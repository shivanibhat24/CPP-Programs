class Solution {
public:    
    struct SumCount
    {
        int sum{0};
        int cnt{0};
    };
    vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
        int size =  static_cast<int>(colors.size());
        vector<SumCount> sum_cnts(size+1);
        int total_cnt = 0;
        int total_sum = 0;
        auto add = [&](int inSize, int inCnt) {
            if (inSize < 3)
              return;
            total_cnt += inCnt;
            auto ip1 = inSize + 1;
            total_sum += inCnt * ip1;
            for (auto p = inSize; p <= size; p += (p & -p))
            {
                auto & s = sum_cnts[p];
                s.sum += ip1 * inCnt;
                s.cnt += inCnt;
            }
        };
        auto calc = [&](int inSize) {
            int64_t sum = 0;
            int cnt = 0;
            for (auto p = inSize; p > 0; p -= (p& -p))
            {
                auto & s = sum_cnts[p];
                sum += s.sum;
                cnt += s.cnt;
            }
            return make_pair(sum, cnt);
        };
        bool total_alternating = true;
        typedef map<int, int> RegionMap;
        typedef RegionMap::iterator RegIt;
        RegionMap regions;
        auto dec = [&](RegIt it) { return it != regions.begin() ? --it : --regions.end(); };
        auto inc = [&](RegIt it) { ++it; return it != regions.end() ? it : regions.begin(); }; 
        auto find = [&](int p) { auto it = regions.upper_bound(p); return dec(it); };
        auto change_size = [&](RegIt it, int diff) {auto & sz = it->second; add(sz, -1); sz += diff; add(sz, 1); };
        auto erase_it = [&] (RegIt it) { add(it->second, -1); regions.erase(it); };
        auto emplace = [&] (int p, int sz) { add(sz, 1); regions.emplace(p, sz); };
        auto split = [&](int p) {
          auto it = find(p);
          auto sr = it->first;
          auto csize = it->second;
          auto er = (it->first + csize-1) % size;
          if (csize == 1)
          {
            auto pit = dec(it);
            auto nit = inc(it);
            if (pit == nit)
            {
              total_alternating = true;
              erase_it(pit);
              regions.clear();
              return;
            }
            change_size(pit, 1 + nit->second);
            erase_it(it);
            erase_it(nit);
            return;
          }
          if (p == sr)
          {
            emplace((p + 1) % size, csize-1);
            auto pit = dec(it);
            change_size(pit, 1);
            erase_it(it);
            return;
          }
          else if (p == er)
          {
            auto nit = inc(it);
            change_size(it, -1);
            emplace(er, nit->second+1);
            erase_it(nit);
            return;
          }
          auto s1 = (p - sr + size) % size;
          change_size(it, s1 - csize);
          emplace(p, 1);
          emplace((p+1) % size, csize - 1 - s1 );
        };
        int last_i = 0;
        for (int i = 1; i < size; ++i)
        {
            if (colors[i] == colors[i-1])
            {
                auto sz = i - last_i;
                regions.emplace(last_i, sz);
                add(sz, 1);
                last_i = i;
            }
        }
        total_alternating = regions.empty() && (size % 2 == 0);
        if (total_alternating)
        {
        }
        else if (regions.empty())
        {
          regions.emplace(0, size);
          add(size, 1);
        }
        else if (colors.front() != colors.back())
        {
          auto fst_it = regions.begin();
          emplace(last_i, fst_it->second + size - last_i);   
          erase_it(fst_it);
        }
        else
        {
          emplace(last_i, size - last_i);   
        }
        std::vector<int> results;
        for (const auto & q : queries)
        {
            if (q[0] == 1)
            {
              if (!total_alternating)
              {
                auto n = q[1];
                auto [sn, cn] = calc(n-1);
                auto r = total_sum - sn - n * (total_cnt - cn);
                results.push_back(r);
              }
              else
              {
                results.push_back(size);
              }
            }
            else
            {
                auto p = q[1];
                auto nc = q[2];
                auto & cc = colors[p];
                if (cc == nc)
                  continue;
                cc = nc;
                if (total_alternating)
                {
                  regions.emplace(p, 1);
                  auto p1 = (p + 1) % size;
                  regions.emplace(p1, size - 1);
                  add(size - 1, 1);
                  total_alternating = false;
                }
                else
                {
                  split(p);
                }
            }
        }
        return results;
    }
};
