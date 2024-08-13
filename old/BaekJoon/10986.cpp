#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int N, M;
    vector<long long> cached;
    map<int, int> mp;

    cin >> N >> M;
    cached.resize(N + 1, 0);

    long long answer = 0;
    for (int i = 0; i < N; i++)
    {
        long long c;
        cin >> c;
        cached[i + 1] = (cached[i] + c) % M;

        auto beforeCount = mp[cached[i + 1]];
        answer += beforeCount;

        mp[cached[i + 1]]++;
    }
    cout << mp[0] + answer;
}