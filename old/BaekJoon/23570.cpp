#include <iostream>
#include <algorithm>

using namespace std;

int xyz[3];

int f1(int z)
{
    return z / 2 - ((z % 2) ? 0 : 1);
}
int f2(int z)
{
    int sub1 = z - xyz[0] - 1;
    int ret = f1(z) - sub1;
    return (ret >= 0) ? ret : 0;
}
int main()
{
    cin >> xyz[0] >> xyz[1] >> xyz[2];
    sort(xyz, xyz + 3);
    long long answer = 0ll;
    for (int i = 3; i <= xyz[0]; i++)
    {
        answer += static_cast<long long>(f1(i) * 48);
    }
    for (int i = xyz[0] + 1; i <= xyz[1]; i++)
    {
        answer += static_cast<long long>(f2(i) * 16);
    }
    cout << answer << "\n";
}