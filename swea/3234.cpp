#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;

int answer;
int N;
int total_sum;

int v[10];
int pi[10];
int ex[10];
int vi[10];


void init_pi()
{
    pi[0] = 1;
    ex[0] = 1;
    for (int i = 1; i < 10; i++)
    {
        pi[i] = pi[i - 1] * i;
        ex[i] = ex[i - 1] * 2;
    }
}

void dp(int left_sum, int right_sum, int count)
{
    if (count == N)
    {
        answer++;
        return;
    }
    if( total_sum - left_sum <= left_sum) {
        int remain = N - count;
        answer += pi[remain]*ex[remain];
        return;
    }
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        if(!vi[i])
        {
            vi[i] = 1;

            dp(left_sum + v[i], right_sum, count + 1);
            if (left_sum >= right_sum + v[i])
            {
                dp(left_sum, right_sum + v[i], count + 1);
            }

            vi[i] = 0;
        }
    }
}

int main()
{
    init_pi();

    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        answer = 0;
        total_sum = 0;
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
            total_sum += v[i];
            vi[i] = 0;
        }
        dp(0, 0, 0);
        cout << "#" << test_case << " " << answer << "\n";
    }
}