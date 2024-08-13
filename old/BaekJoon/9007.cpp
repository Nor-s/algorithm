#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

// k == 보트의 특정 값
// n == 각 반의 학생 수 4
int k, n;
vector<vector<int>> students;
vector<int> sum1;
vector<int> sum2;
int answer = INT32_MAX;

void checkAnswer(int value)
{
    if (answer == INT32_MAX)
    {
        answer = value;
        return;
    }

    int currentAnswerDiff = abs(k - answer);
    int diff = abs(k - value);
    if ((diff == currentAnswerDiff && value < answer) ||
        (currentAnswerDiff > diff))
    {
        answer = value;
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> k >> n;
        students = vector<vector<int>>(4, vector<int>(n));
        answer = INT32_MAX;
        sum1.clear();
        sum2.clear();

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> students[i][j];
            }
            sort(students[i].begin(), students[i].end());
        }
        for (int j = 0; j < n; j++)
        {
            for (int kk = 0; kk < n; kk++)
            {
                sum1.push_back(students[0][j] + students[1][kk]);
                sum2.push_back(students[2][j] + students[3][kk]);
            }
        }
        sort(sum2.begin(), sum2.end());
        for (int i = 0; i < sum1.size(); i++)
        {
            int value = k - sum1[i];
            int idx = lower_bound(sum2.begin(), sum2.end(), value) - sum2.begin();
            for (int ii = idx - 1; ii < idx + 2; ii++)
            {
                if (0 <= ii && ii < sum2.size())
                {
                    checkAnswer(sum2[ii] + sum1[i]);
                }
            }
        }

        cout << answer << "\n";
    }
}
