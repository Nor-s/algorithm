#include <deque>
#include <iostream>
#include <string>

using namespace std;

deque<int> dq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        if (s[3] == 'h')
        {
            int a;
            cin >> a;
            if (s[5] == 'f')
            {
                dq.push_front(a);
            }
            else
            {
                dq.push_back(a);
            }
        }
        else if (s[0] == 's')
        {
            cout << dq.size() << "\n";
        }
        else if (s[0] == 'e')
        {
            cout << (dq.empty() ? 1 : 0) << "\n";
        }
        else if (dq.empty())
        {
            cout << -1 << "\n";
        }
        else if (s[0] == 'p')
        {
            if (s.back() == 't')
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (s[0] == 'f')
        {
            cout << dq.front() << "\n";
        }
        else
        {
            cout << dq.back() << "\n";
        }
    }
}