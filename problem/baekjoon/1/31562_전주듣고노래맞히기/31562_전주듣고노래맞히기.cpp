
// s:
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <map>
#include <string>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    std::map<std::string, int> threenote_stringid;
    std::vector<std::string> namelist;

    for (int i = 0; i < N; i++)
    {
        int len;
        cin >> len;
        std::string name;
        cin >> name;
        std::string key;
        for (int j = 0; j < 7; j++)
        {
            char tmp;
            cin >> tmp;
            if (j < 3)
            {
                key.push_back(tmp);
            }
        }
        auto it = threenote_stringid.insert({key, i + 1});

        if (!it.second)
        {
            it.first->second = -1;
        }
        namelist.push_back(name);
    }

    for (int i = 0; i < M; i++)
    {
        std::string key;
        for (int j = 0; j < 3; j++)
        {
            char tmp;
            cin >> tmp;
            key.push_back(tmp);
        }
        int id = threenote_stringid[key];
        if (id == -1)
            cout << "?" << endl;
        else if (id > 0)
            cout << namelist[id - 1] << endl;
        else
            cout << "!" << endl;
    }
}