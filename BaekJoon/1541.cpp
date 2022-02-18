#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int sum(string &s)
{
    int ret = 0;
    auto idx = string::npos;
    while (string::npos != (idx = s.find("+")))
    {
        ret += stoi(s.substr(0, idx));
        s = s.substr(idx + 1);
    }
    return ret + stoi(s);
}

int re(string s, int sign)
{
    auto idx = s.find("-");
    if (idx == string::npos)
    {
        return sign * sum(s);
    }
    return sign * re(s.substr(0, idx), 1) + re(s.substr(idx + 1), -1);
}

int main()
{
    string s;
    cin >> s;
    cout << re(s, 1);
}