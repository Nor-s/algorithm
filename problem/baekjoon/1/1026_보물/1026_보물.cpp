// https://www.acmicpc.net/problem/1026
// s: 09:16

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

int main()
{
    int N;
    cin >> N;

    // input1[0] x input2[0] + ...
    std::vector<int> input1(N);
    std::vector<int> input2(N);

    std::for_each(input1.begin(), input1.end(), [&](int &n) { cin >> n; });
    std::for_each(input2.begin(), input2.end(), [&](int &n) { cin >> n; });

    std::sort(input1.begin(), input1.end());
    std::sort(input2.begin(), input2.end(), std::greater<int>());

    std::transform(input1.begin(), input1.end(), input2.begin(), input1.begin(),
                   std::multiplies<int>());

    std::cout << std::accumulate(input1.begin(), input1.end(), 0) << std::endl;
}