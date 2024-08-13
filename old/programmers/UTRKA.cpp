#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> dic;
    std::pair<std::map<string,int>::iterator,bool> isFail;

    for(int i = 0; i < participant.size(); i++)
    {
        isFail = dic.insert ( std::pair<string,int>(participant[i],1) );
        if(isFail.second == false)
            dic[participant[i]]++;
    }

    for(int i = 0; i < completion.size(); i++)
        dic[completion[i]]--;

    for(int i = 0; i < participant.size(); i++)
        if(dic[participant[i]] != 0)
            return participant[i];

    return "";
}


int main()
{
    int n, m;
    cin>>n;
    cin>>m;
    vector<string> vs0;
    vector<string> vs1;
    while(n--)
    {
        string tmp;
        cin>>tmp;
        vs0.push_back(tmp);
    }
    while(m--)
    {
        string tmp;
        cin>>tmp;
        vs1.push_back(tmp);
    }
    cout<<solution(vs0, vs1);
}