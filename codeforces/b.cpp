#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// a[1...n] = [a1, a2, ..., am]
// 1. select index l and r 1 ~ n
// 2. replace seg[l~r] to left offset d

// output : l r d

// min => sort
// min /

vector<vector<int>> solve(vector<int> &el)
{
    vector<vector<int>> ret;
    return ret;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> el;
        el.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> el[i];
        }
        vector<vector<int>> els = solve(el);
        for (int i = 0; i < els.size(); i++)
        {
            for (int j = 0; j < els[i].size(); j++)
            {
                cout << els[i][j] << " ";
            }
            cout << "\n";
        }
    }
}