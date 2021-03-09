#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[2001][20];
int dfs(int here, const vector<int>& numbers, const int& target, int sum)
{
    int& ret = cache[1000 + sum][here];
    if(ret != -1) return ret;
    if(here == numbers.size())
        if(sum == target) return 1;
        else return 0;
    
    ret = 0;
    ret += dfs(here + 1, numbers, target, sum + numbers[here]);
    ret += dfs(here + 1, numbers, target, sum - numbers[here]);
    
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    memset(cache, -1, sizeof cache);
    answer = dfs(0, numbers, target, 0);
    return answer;
}

int main()
{
    int m;
    cin>>m;
    vector<int> num;
    while(m--)
    {
        int tmp;
        cin>>tmp;
        num.push_back(tmp);
    }
    int target;
    cin>>target;
    cout<<solution(num, target)<<"\n";
}