//https://www.acmicpc.net/problem/25682
#include <iostream>

using namespace std;

int psum1[2002][2002];
int psum2[2002][2002];

// B가 첫번째일 때, W가 첫번째일 때 각각 2d 누적합을 구하기
int getMinKK(int N, int M, int K, int psum[2002][2002])
{
    int minkk = 1e9;
    int k = K;
    for (int i = 1; i <= N - K + 1; i++)
    {
        for (int j = 1; j <= M - K + 1; j++)
        {
            int kk = psum[i + K - 1][j + K - 1] - psum[i + K - 1][j - 1] - psum[i - 1][j + k - 1] + psum[i - 1][j - 1];
            minkk = min(kk, minkk);
        }
    }
    return minkk;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    char checkWord[] = {'W', 'B'};
    for (int i = 1; i <= N; i++)
    {
        int start1 = (i % 2 == 0);
        int start2 = (i % 2 == 1);
        for (int j = 1; j <= M; j++)
        {
            char c;
            cin >> c;

            int isRepaint1 = (checkWord[start1] != c);
            int isRepaint2 = (checkWord[start2] != c);

            psum1[i][j] = isRepaint1 + psum1[i - 1][j] + psum1[i][j - 1] - psum1[i - 1][j - 1];
            psum2[i][j] = isRepaint2 + psum2[i - 1][j] + psum2[i][j - 1] - psum2[i - 1][j - 1];

            start1 = (start1 + 1) % 2;
            start2 = (start2 + 1) % 2;
        }
    }
    int min1 = getMinKK(N, M, K, psum1);
    int min2 = getMinKK(N, M, K, psum2);
    cout << min(min1, min2);
}
