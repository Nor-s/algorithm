#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
// 11 16
#include <queue>
#include <map>

using namespace std;

//1
// a->d : an-d an-d+1 .... an-1, a0, a1 ,... an-d-1
// ai->d = a(i+n-d)mod n
//2
// ai & ai->d  => and
// only zero can? step count = ?

void bfs()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        // size, offset
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
}