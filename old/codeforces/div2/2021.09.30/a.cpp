#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define COUT(a) cout << a << "\n"
#define CCOUT(a, b) cout << a << b << "\n"
#define CCCOUT(a, b, c) cout << a << b << c << "\n"

using namespace std;
using ll = long long;
const int MOD = 1000000007;
int n;
string s;
ll answer = 0;

long long update_check(vector<bool> &check, vector<int> &array, int s, int e, long long count)
{
    for (int i = s - 1; i < s + 1; i++)
    {
        if (i < 0 || i >= n * 2)
        {
            continue;
        }
        count -= (int)check[i];
        check[i] = false;
        if (array[i] > array[i + 1])
        {
            check[i] = true;
            count++;
        }
    }
    for (int i = e - 1; i < e + 1; i++)
    {
        if (i < 0 || i >= n * 2)
        {
            continue;
        }
        count -= (int)check[i];
        check[i] = false;
        if (array[i] > array[i + 1])
        {
            check[i] = true;
            count++;
        }
    }
    return count;
}

void perm(vector<int> &array, vector<bool> &check, int s, int e, long long count)
{

    if (count >= n || s == e)
    {
        return;
    }
    else
    {
        cout << count << "a: ";
        for (int i = 0; i < n * 2; i++)
        {
            cout << array[i] << " ";
        }
        cout << "\n";
        answer = (answer + 1) % MOD;
        for (int i = s + 1; i <= e; ++i)
        {
            swap(array[s], array[i]);
            long long tmp = update_check(check, array, s, i, count);
            perm(array, check, i, tmp);

            swap(array[s], array[i]);
            update_check(check, array, idx, i, count);
        }
    }
}
long long solve(int N)
{
    vector<int> nn(N);
    vector<bool> check(N, false);

    for (int i = 1; i <= N; i++)
    {
        nn[i - 1] = i;
    }

    perm(nn, check, 0, 0);
    return answer % MOD;
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
        cin >> n;
        COUT(solve(2 * n));
    }
}