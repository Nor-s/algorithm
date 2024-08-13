#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    int B, C;
    cin >> B >> C;

    long long count = 0;
    for (int i = 0; i < N; i++)
    {
        {
            v[i] -= B;
            count++;
        }
        if (v[i] > 0)
        {
            count += (v[i] / C);
            if (v[i] % C != 0)
                count++;
        }
    }
    cout << count;
}
