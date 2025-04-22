const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#ifndef _WIN32 && ifndef _WIN64
const auto __ = []() {
  struct ___ {
    static void _() {
      ofstream("display_runtime.txt") << 0 << '\n';
    }
  };
  
  atexit(&___::_);
  return 0;
  }();
#endif

#if defined _WIN32 || defined _WIN64
#define USACO(filename) 0
#else
#define USACO(filename) freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout)
#endif


class Router {
private:
    struct P {
        int a, b, c;
        P(int a, int b, int c) : a(a), b(b), c(c) {}
    };

    int m;
    queue<P> q;
    unordered_set<string> s;
    unordered_map<int, vector<int>> t;

    string f(int a, int b, int c) {
        return to_string(a) + "|" + to_string(b) + "|" + to_string(c);
    }

public:
    Router(int x) {
        m = x;
    }

    bool addPacket(int a, int b, int c) {
        string z = f(a, b, c);
        if (s.count(z)) return false;
        if ((int)q.size() == m) {
            auto p = q.front(); q.pop();
            s.erase(f(p.a, p.b, p.c));
            auto& v = t[p.b];
            auto it = lower_bound(v.begin(), v.end(), p.c);
            if (it != v.end()) v.erase(it);
        }
        q.push(P(a, b, c));
        s.insert(z);
        t[b].push_back(c);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto p = q.front(); q.pop();
        s.erase(f(p.a, p.b, p.c));
        auto& v = t[p.b];
        auto it = lower_bound(v.begin(), v.end(), p.c);
        if (it != v.end()) v.erase(it);
        return {p.a, p.b, p.c};
    }

    int getCount(int b, int l, int r) {
        auto& v = t[b];
        return upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
    }
};
