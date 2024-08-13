#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
// 6 8

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k; // k<= scire   n >= k
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        a.push_back(e);
    }
    int i = 0;
    for (i = 0; i < a.size(); i++)
    {
        if (a[i] == 0 || a[k - 1] > a[i])
        {
            break;
        }
    }
    cout << i;
}