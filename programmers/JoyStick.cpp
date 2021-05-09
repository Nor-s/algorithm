#include <string>
#include <iostream>
#include <vector>

using namespace std;

int alphabetMove[26];

void calcAlphabetMove()
{
    int move = 0;
    alphabetMove[0] = 0;
    while(++move <= 13)
    {
        alphabetMove[move] = alphabetMove[26 - move] = move;
    }
}
void initialize(string& name, vector<bool>& visited, int &n)
{
    for(int i = 0; i < name.size(); i++)
        if(name[i] == 'A')
        {
            visited[i] = true;
            n++;
        }
}

int findNext(string& str, int index, vector<bool>& visited, int& answer)
{
    string tmp = str + str + str;
    int current = index + str.size();
    int left, right;
    for(int i = current + 1; i < tmp.size(); i++)
        if(tmp[i] != 'A' && !visited[i%str.size()])
        {
            right = i;
            break;
        }
        
    for(int j = current - 1; 0 <= j; j--)
        if(tmp[j] != 'A' && !visited[j%str.size()])
        {
            left = j;
            break;
        }
    
    answer += min(right - current, current - left);
    
    return ((right - current > current - left) ? left: right)%str.size();
}


int solution(string name) {
    int answer = 0, n = 0, cursor = 0;
    vector<bool> visited(name.size(), false);
    
    calcAlphabetMove();
    initialize(name, visited, n);

    while(n < name.size())
    {
        if(visited[cursor])
        {
            cursor = findNext(name, cursor, visited, answer);
            continue;
        }
        answer += alphabetMove[name[cursor] - 'A'];
      	visited[cursor] = true;
        n++;
    }
    
    return answer;
}

//"JEROEN"	56
//"JAN"	23
int main()
{
    string name;
    cin>>name;
    cout<<solution(name)<<"\n";
}