#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <tuple>
#include <iterator>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <unordered_map>

#define cout1(a) cout << a
#define cout2(a, b) cout << a << b
#define cout3(a, b, c) cout << a << b << c
#define cout4(a, b, c, d) cout << a << b << c << d
#define cout5(a, b, c, d, e) cout << a << b << c << d << e
#define coutvi(a, b) copy(a, b, ostream_iterator<int>(cout, " "))
#define coutvc(a, b) copy(a, b, ostream_iterator<char>(cout, " "))

using namespace std;

class LFUCache
{
public:
    struct node
    {
        int key;
        int value;
        int freq;
        node(int k, int v, int f) : key(k), value(v), freq(f) {}
    };
    unordered_map<int, node *> key_index;
    vector<node *> vp;
    int cap = 0;
    LFUCache(int capacity)
    {
        cap = capacity;
        key_index.clear();
        vp.resize(capacity, new node(-1, -1, -1));
    }
    void sort_vp()
    {
        sort(vp.begin(), vp.end(), [](auto *p_pii1, auto *p_pii2)
             { return p_pii1->freq < p_pii2->freq; });
    }
    int get(int key)
    {
        // map find key
        if (auto it = key_index.find(key); it != key_index.end())
        {
            auto p_pii = it->second;
            p_pii->freq++;
            if (vp[0] == p_pii)
            {
                sort_vp();
            }
            return p_pii->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // map find key
        if (auto it = key_index.find(key); it != key_index.end())
        {
            auto p_pii = it->second;
            p_pii->freq++;
            p_pii->value = value;
            if (vp[0] == p_pii)
            {
                sort_vp();
            }
        }
        else
        {
            if (cap == 0)
                return;
            if (vp[0]->key != -1)
            {
                key_index.erase(vp[0]->key);
            }
            bool do_sort = false;
            if(vp[0]->key == -1) {
                do_sort = true;
            }
            vp[0]->key = key;
            vp[0]->value = value;
            vp[0]->freq = 1;
            key_index[key] = vp[0];

            if(do_sort) {
                sort_vp();
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
    }
}