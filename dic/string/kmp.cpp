#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

void failure(const string &B, vector<long long> &fail)
{
    size_t n = B.size();
    fail.resize(n);
    fail[0] = -1;
    for (int start = 1; start < n; start++)
    {
        int before = fail[start - 1];
        while (B[before + 1] != B[start] && (before >= 0))
            before = fail[before];
        if (B[before + 1] == B[start])
            fail[start] = before + 1;
        else
            fail[start] = -1;
    }
}

ull kmpSearch(const string &A, const string &B, vector<long long> &fail)
{
    ull count = 0;
    long long i = 0, j = -1;
    long long n = A.size(), m = B.size();
    while (i < n)
    {
        if (A[i] == B[j + 1])
        {
            if (j + 1 == m - 1)
            {
                j = fail[j + 1];
                count++;
            }
            else
            {
                j++;
            }
            i++;
        }
        else
        {
            if (j == -1)
            {
                i++;
            }
            else
            {
                j = fail[j];
            }
        }
    }
    return count;
}