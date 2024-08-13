#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution
{
public:
    struct trie
    {
        bool is_exist = false;
        bool is_end = false;
        vector<trie> childs;
    };
    trie *root;

    void make_tree(trie *current_t, string &s, int current_idx)
    {
        if (current_t->childs.size() == 0)
        {
            current_t->childs = vector<trie>(27);
        }
        char ch = s[current_idx];
        trie *next_t = &current_t->childs[ch - 'a'];
        next_t->is_exist = true;

        if (current_idx == s.size() - 1)
        {
            next_t->is_end = true;
            return;
        }
        return make_tree(next_t, s, current_idx + 1);
    }

    bool is_concatenated(trie *current_t, trie *check_t, string &s, int current_idx, int count)
    {
        if (s.size() == current_idx)
        {
            return 0 < count && check_t->is_end;
        }

        char ch = s[current_idx];
        trie *next_t = &current_t->childs[ch - 'a'];
        if (check_t->childs.size() == 0)
        {
            return is_concatenated(current_t, root, s, current_idx, count + 1);
        }

        trie *next_check_t = &check_t->childs[ch - 'a'];
        bool ret = false;
        if (next_check_t->is_exist)
        {
            if (next_check_t->is_end)
            {
                ret |= is_concatenated(next_t, root, s, current_idx, count + 1);
            }
            if (ret)
            {
                return ret;
            }
            ret |= is_concatenated(next_t, next_check_t, s, current_idx, count);
        }
        return ret;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> ret;
        sort(words.begin(), words.end());
        trie tree;
        tree.is_exist = true;
        root = &tree;

        for (auto &s : words)
        {
            make_tree(&tree, s, 0);
        }
        for (auto &s : words)
        {
            if (is_concatenated(&tree, &tree, s, 0, 0))
            {
                ret.push_back(s);
            }
        }
        return ret;
    }
};

int main()
{
}