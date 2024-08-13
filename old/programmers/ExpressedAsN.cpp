#include <string>
#include <vector>
#include <map>
using namespace std;
vector<int> makeGraph(int N)
{
    vector<int> ret;
    int tmp{0};
    for(int i = 1; i <= 8; i++)
    {
        tmp = tmp*10 + N;
        ret.push_back(tmp);
    }
    return ret;
}
map<int, int> cache[9];
int dp(vector<int>& nSet, int number, int c, int expr)
{    
    if(expr == number) return c;
    if(cache[c].count(expr) != 0)
        return cache[c][expr];
    
    int ret = 9;
    
    for(int i = 0; i < nSet.size(); i++)
    {
        if(c + i + 1 > 8) continue;
        ret = min(ret, dp(nSet, number, c + i + 1, expr + nSet[i]));
        ret = min(ret, dp(nSet, number, c + i + 1, expr * nSet[i]));
        ret = min(ret, dp(nSet, number, c + i + 1, expr - nSet[i]));
        ret = min(ret, dp(nSet, number, c + i + 1, expr / nSet[i]));
    }
    cache[c][expr] = ret;
    return ret;
}
int solution(int N, int number) {
    int answer = 0;
    vector<int> nSet = makeGraph(N);
    answer = dp(nSet, number, 0, 0);
    if(answer == 9)
        answer = -1;
    return answer;
}