#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void restore(const vector<int>& array, vector<int>& tmp, int a, int b)
{
    for(int i = a; i < b; i++)
        tmp[i] = array[i];
}
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer, tmp(array);
    for(vector<int>& var : commands)
    {
        int a = var[0] - 1;
        int b = var[1];
        int k = var[2];
        
        sort(tmp.begin() + a, tmp.begin() + b);
        answer.push_back(tmp[a+k-1]);
        restore(array, tmp, a, b);
    }
    return answer;
}