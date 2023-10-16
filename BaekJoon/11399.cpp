#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <string>
#include <iterator>

using namespace std;

int N;
vector<int> P;

int main()
{
    cin >> N;
    P.resize(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    int sum = 0;
    int answer = 0;
    sort(P.begin(), P.end());
    for (int i = 0; i < N; i++)
    {
        answer += P[i] * (N - i);
    }
    cout << answer;
}