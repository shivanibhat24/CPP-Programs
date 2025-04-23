#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

const int C = 10000;
const int K = 100001;
const int Q = 20001;

struct Item
{
    int key;
    int value;
    int count;
    int prev;
    int next;
    Item() {}
};

short m[K];
Item v[C];
int h[Q];

class LFUCache {
    int capacity;
    int n;
    
    void pushFront(int k, Item& a)
    {
        v[a.prev].next = a.next;
        v[a.next].prev = a.prev;
        if (a.next == k) h[a.count] = -1;
        else if (h[a.count] == k) h[a.count] = a.next;
        a.count++;
        int t = h[a.count];
        if (t == -1)
        {
            a.prev = k;
            a.next = k;
        }
        else
        {
            a.next = t;
            a.prev = v[t].prev;
            v[a.next].prev = k;
            v[a.prev].next = k;
        }
        h[a.count] = k;
    }

public:
    LFUCache(int capacity) : capacity(capacity), n(0)
    {
        fill(m, m+K, -1);
        fill(h, h+Q, -1);
    }
    
    int get(int key)
    {
        int i = m[key];
        if (i == -1) return -1;
        auto& a = v[i];
        pushFront(i, a);
        return a.value;
    }
    
    void put(int key, int value)
    {
        int p = m[key];
        if (p == -1)
        {
            int j = n;
            if (n >= capacity)
            {
                int i=0;
                for (; h[i] == -1; i++);
                j = v[h[i]].prev;
                auto& t = v[j];
                if (h[i] == j) h[i] = -1;
                else
                {
                    v[t.prev].next = t.next;
                    v[t.next].prev = t.prev;
                }
                m[t.key] = -1;
            }
            else n++;
            m[key] = j;
            auto& a = v[j];
            a.key = key;
            a.value = value;
            a.count = 1;
            int t = h[1];
            if (t == -1)
            {
                a.prev = j;
                a.next = j;
            }
            else
            {
                a.next = t;
                a.prev = v[t].prev;
                v[a.next].prev = j;
                v[a.prev].next = j;
            }
            h[1] = j;
        }
        else
        {
            pushFront(p, v[p]);
            v[p].value = value;
        }
    }
};
