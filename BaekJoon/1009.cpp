
#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        int s = a;
        for (int j = 0; j < b - 1; j++)
        {
            s = (a * s) % 10;
        }
        if (s == 0)
            s = 10;

        cout << s << "\n";
    }
}