#include <string>
#include <vector>
#include <map>

using namespace std;

#include <string>
#include <vector>
#include <map>

using namespace std;


long long solution(vector<int> weights)
{
    long long answer = 0;
    map<int, int> person;
    for (int i = 0; i < weights.size(); i++)
    {
        person[weights[i]]++;
    }

    map<int, long long> weight_count;
    for (auto &e : person)
    {
        weight_count[e.first * 2]++;
        weight_count[e.first * 3]++;
        weight_count[e.first * 4]++;
    }

    for (auto &w : weight_count)
    {
        if (w.second >= 2)
        {
            answer += (w.second * w.second - 1) / 2L;
        }
    }
    for(auto &p : person) {
        if(p.second >=2) {
            
        }
    }

    return answer;
}

int main()
{
}