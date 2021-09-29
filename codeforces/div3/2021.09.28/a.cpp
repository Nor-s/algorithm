#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>

using namespace std;

// eachturn -> two action
// erase ;a; , b'
// erase 'b' and  c
// erase two
// s = ""
char ff[2] = {'A', 'B'};
char ss[2] = {'B', 'C'};

tuple<bool, string> is_can(int i, string &s)
{
    char fff = (i == 0) ? ff[0] : ss[0];
    char sss = (i == 0) ? ff[1] : ss[1];
    string::size_type fidx;
    string::size_type sidx;

    fidx = s.find(fff);
    if (fidx == string::npos)
    {
        return make_pair<bool, string>(false, " ");
    }
    else
    {
        string tmp = s;
        tmp.erase(fidx, 1);

        sidx = tmp.find(sss);
        if (sidx == string::npos)
        {
            return {false, tmp};
        }

        tmp.erase(sidx, 1);

        return {true, tmp};
    }
}

int dp(map<string, int> &dic, string &s)
{
    int &ret = dic[s];
    if (ret != 0)
    {
        return ret;
    }
    ret = 2;
    if (s.length() == 0)
    {
        return 1;
    }

    for (int i = 0; i < 2; i++)
    {
        pair<bool, string> tmp = is_can(i, s);
        if (tmp.first)
        {

            bool is_ccan = dp(dic, tmp.second);
            if (is_ccan == true)
            {
                ret = 1;
                return ret;
            }
        }
    }

    return ret;
}

string solve(string &s)
{
    map<string, int> dic;
    string ret = "YES";
    if (dp(dic, s) == 2)
    {
        ret = "NO";
    }
    return ret;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; // max = 50
        cin >> s;
        //cout << is_can(0, s).second << "\n";
        cout << solve(s) << "\n";
    }
}