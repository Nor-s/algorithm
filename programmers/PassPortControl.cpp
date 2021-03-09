#include <string>
#include <iostream>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    return answer;
}

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> times;
    while(m--)
    {
        int tmp;
        cin>>tmp;
        times.push_back(tmp);
    }
    cout<<solution(n, times)<<"\n";
}