#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        deque<int> answer;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (!answer.empty() && answer.front() > a)
            {
                answer.push_front(a);
            }
            else
            {
                answer.push_back(a);
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
    }
}