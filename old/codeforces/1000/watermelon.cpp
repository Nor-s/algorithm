#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
//5 10
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int W;
    cin >> W; // weight
    if (W % 2 == 0 && 2 != W)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}