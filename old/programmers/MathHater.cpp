#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;


vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[] = {1,2,3,4,5}, b[] = {2,1,2,3,2,4,2,5}, c[] = {3,3,1,1,2 ,2,4,4,5,5}, d[] = {0, 0, 0};
    for(int i = 0; i < answers.size(); i++)
    {
        d[0] += static_cast<int>(a[i%5] == answers[i]);
        d[1] += static_cast<int>(b[i%8] == answers[i]);
        d[2] += static_cast<int>(c[i%10] == answers[i]);
    }
    answer.push_back(0+1);
    for(int i = 1; i < 3; i++)
    {
        if(d[answer.back()-1] < d[i])
        {
            answer.clear(); 
            answer.push_back(i+1);
        }
        else if(d[answer.back()-1] == d[i])
            answer.push_back(i+1);
    }
    return answer;
}
int main()
{
    vector<int> tmp;
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        tmp.push_back(a);
    }
    tmp = solution(tmp);
    for(auto var : tmp)
    {
        cout<<var<<" ";
    }
}