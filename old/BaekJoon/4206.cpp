#include <iostream>
#include <vector>
#include <string>
#include <cstring>
// 9
using namespace std;

using ull = unsigned long long;

const string first = "0";
const string second = "1";
int n;
string p; // 100,000

string tmpstr[2];
string m_[3];
void failure(const string &B, vector<long long> &fail);
ull kmpSearch(const string &A, const string &B, vector<long long> &fail);
// b  :i
// f  :i+1
// f + b : i+2
// m = f + b
// fb + f
// m = b + f
// fbf + fb
// m = f + f
// fbffb + fbf
// m = b + f
// fbffbfbf + fbffb
// m = f + f
// fbffbfbffbffb + fbffbfbf
//  m = b + f
//  m = f + f
//  m = b + f
//...

vector<long long> fail;

ull cached[111];
ull F(int i, int count)
{
    if (i > n)
    {
        return cached[i - 1];
    }
    string *mid{nullptr};

    if (count == 0)
    {
        mid = &m_[0];
    }
    else if (count % 2 == 1)
    {
        mid = &m_[1];
    }
    else if (count % 2 == 0)
    {
        mid = &m_[2];
    }

    ull isFind = 0;

    if (p.size() > 1)
    {
        isFind = kmpSearch(*mid, p, fail);
    }

    cached[i] = cached[i - 1] + cached[i - 2] + isFind;

    return F(i + 1, count + 1);
}
void init_mid()
{
    ull fs = tmpstr[1].size() - p.size() + 1;
    ull bs = tmpstr[0].size() - p.size() + 1;
    ull w = p.size() * 2 - 2;

    m_[0] = (tmpstr[1] + tmpstr[0]).substr(fs, w);
    m_[1] = (tmpstr[0] + tmpstr[1]).substr(bs, w);
    m_[2] = (tmpstr[1] + tmpstr[1]).substr(fs, w);
}

ull solve()
{
    tmpstr[0] = first;
    tmpstr[1] = second;
    failure(p, fail);
    int i = 0;
    while (tmpstr[0].size() < p.size())
    {
        i++;
        string tmp = tmpstr[1] + tmpstr[0];
        tmpstr[0] = tmpstr[1];
        tmpstr[1] = tmp;
    }
    if (n < i)
    {
        return 0;
    }
    ull b_c = kmpSearch(tmpstr[0], p, fail);
    if (b_c != 0)
    {
        cached[i] = b_c;
    }

    ull f_c = kmpSearch(tmpstr[1], p, fail);
    if (f_c != 0)
    {
        cached[i + 1] = f_c;
    }
    init_mid();

    ull ret = F(i + 2, 0);
    if (n == i)
    {
        return cached[i];
    }
    else if (n == i + 1)
    {
        return cached[i + 1];
    }
    else
    {
        return ret;
    }
}

int main()
{
    // freopen("1input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);

    cout.tie(0);
    cin.tie(0);

    int i = 1;
    while (cin >> n >> p)
    {
        if (n < 0)
            break;

        memset(cached, 0, sizeof(cached));

        std::cout << "Case " << i++ << ": ";
        std::cout << solve() << "\n";
    }
    return 0;
}
// left mid mid

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