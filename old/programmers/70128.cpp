#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    transform(a.begin(), a.end(), b.begin(), a.begin(), multiplies<int>());
    return accumulate(a.begin(), a.end(), 0);
}