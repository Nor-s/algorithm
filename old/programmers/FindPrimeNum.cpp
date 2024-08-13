#include <string>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX_INT = 9999999;

bool isPrime[MAX_INT+1];

void era()
{
    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = false;
    isPrime[1] = false;
    int size = sqrt(MAX_INT);
    for(int i = 2; i <= size; i++)
        if(isPrime[i]) 
            for(int j = i*i; j <= MAX_INT; j+= i)
                isPrime[j] = false;
}

vector<int> makeSet(string& str)
{
    vector<int> ret(10, 0);
    for(int i = 0; i < str.size(); i++)
        ret[(int)str[i] - '0']++;
        
    return ret;
}

void dfs(vector<int>& numSet, int sum, int& answer)
{
    if(isPrime[sum])
        answer++;
    for(int i = 0; i < 10 ; i++)
    {
        if(numSet[i] == 0 || (i == 0 && sum == 0)) continue;
        
        numSet[i]--;
        dfs(numSet, sum*10 + i, answer);
        numSet[i]++;
    }
}
int solution(string numbers) {
    int answer = 0;
    era();
    vector<int> numSet = makeSet(numbers);
    dfs(numSet,0, answer);
    return answer;
}