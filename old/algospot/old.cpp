#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n;
string words[1000];
vector<int> topology;
vector<int> alphabets[26];
vector<int>::iterator iter;
bool visited[26];
int descending;

int toNumber(const char& ch)
{
    return ch - 'a';
}

bool compare(const string& word1, const string& word2)  {
    const char* ch1 = word1.c_str();
    const char* ch2 = word2.c_str();

    while((*ch1 == *ch2)&& (*ch1 != '\0' || *ch2 != '\0'))
    {
        ch1++; 
        ch2++;
    }
    if(*ch1 != '\0'&& *ch2 != '\0') {
        alphabets[toNumber(*ch1)].push_back(toNumber(*ch2));
    }
    if(*ch1 != '\0' && *ch2 == '\0')
        alphabets[toNumber(*(ch1))].push_back(toNumber(*ch2));

    if(*ch1 != '\0' && *ch2 == '\0')
    {
        if(descending > 0) return false;
        descending--;
    }
    if( *ch1 == '\0' && *ch2 != '\0'){
        if(descending<0) return false;
        descending++;
    }

    return true;
}


bool makeGraph() {
    for(int i = 0; i < n-1; i++)
    {
        if(!compare(words[i], words[i+1]))
            return false;
    }
    return true;
}
bool dfs(const int& x) {
    
    visited[x] = true;
    
    
    for(int i = 0 ; i < alphabets[x].size(); i++) {
    
        if(visited[alphabets[x][i]]) {
            iter = topology.end();
            iter = find(topology.begin(), topology.end(), alphabets[x][i]);
            if(iter == topology.end())  return false;
        }
        else
            if(!dfs(alphabets[x][i])) return false;
    }

    topology.push_back(x);
    return true;
}

bool dfsAll() {

    for(int i = 0 ; i < 26; i++) {
        if(!visited[i] && alphabets[i].size()!=0) {
            if(!dfs(i)) 
                return false;
        }
    }
    return true;
}

void tsort(){
    reverse(topology.begin(), topology.end());
    for(int i = 0; i < 26; i++) {
        if(!visited[i]) 
            topology.push_back(i);
    }
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        for(int i = 0; i < 26; i++)
            alphabets[i].clear();
        descending = 0;
        topology.clear();
        memset(visited, false, sizeof visited);

        cin>>n;

        for(int i = 0; i < n; i++) {
            cin>>words[i];
        }
        if(!makeGraph()){
            cout<<"INVALIT HYPOTHESIS\n";
            continue;
        }
        if(!dfsAll())
            cout<<"INVALIT HYPOTHESIS\n";
        else {
            tsort();
            for(int i = 0; i < topology.size(); i++) {
                cout<<(char)('a' + topology[i]);
            }
            cout<<"\n";
        }
    }
}