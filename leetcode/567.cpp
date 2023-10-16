#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    // s2에서 s1의 순열을 포함
    bool checkInclusion(string s1, string s2)
    {
        int s1cnt[26] = {0};
        for (char ch : s1)
            s1cnt[ch - 'a']++;

        if (s1.size() > s2.size())
            return false;

        for (int i = 0; i < s2.size(); i += 1)
        {
            int s2cnt[26] = {0};
            for (int j = i; j < s1.size(); j += 1)
            {
                s2cnt[s2[j] - 'a']++;
                if (s2cnt[s2[j] - 'a'] > s1cnt[s2[j] - 'a'])
                    break;
                if (j - i + 1 == s1.size())
                    return true;
            }
        }
        return false;
    }
};
