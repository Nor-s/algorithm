// b1130
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

/**
 * 1. 각 자리수를 map에 담음, 이때 인덱스를 set으로 관리
 * 2. map을 가장 큰 숫자순으로 순회하면서, 앞에서부터 교체
 *     - 교체: map::set 인덱스 업데이트
 *     - 교체:
 */

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        string s;
        int count = 0;
        cin >> s >> count;

        map<int, set<int>> mp;
        bool has_same_value = false;

        for (int i = 0; i < s.size(); i++)
        {
            int ch = -(s[i] - '0');
            mp[ch].insert(-i);
            if (mp[ch].size() > 1)
            {
                has_same_value = true;
            }
        }
        int str_idx = 0;
        for (auto &e : mp)
        {
            int value = -e.first;
            vector<pair<int, int>> changed;
            vector<int> changed_idx;
            for (auto s_idx : e.second)
            {
                if (s[str_idx] != s[-s_idx])
                {
                    count--;
                    changed.push_back({s[str_idx], str_idx});
                    changed_idx.push_back(-s_idx);
                }
                s[str_idx++] = (char)value + '0';
                if (count == 0)
                {
                    break;
                }
            }
            // 예외: 32888 2
            // 오름차순 2 3
            sort(changed.begin(), changed.end());
            // 내림차순인 인덱스
            //  4 3
            // mp update
            for (int k = 0; k < changed.size(); k++)
            {
                char ch = (char)changed[k].first;
                int chi = -(ch - '0');
                s[changed_idx[k]] = ch;
                mp[chi].erase(-changed[k].second);
                mp[chi].insert(-changed_idx[k]);
            }
            if (count == 0)
            {
                break;
            }
        }
        while (!has_same_value && count != 0)
        {
            swap(s[s.size() - 1], s[s.size() - 2]);
            count--;
        }

        cout << "#" << test_case << " ";
        cout << s << "\n";
    }

    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}