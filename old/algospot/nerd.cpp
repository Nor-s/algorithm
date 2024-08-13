#include <iostream>
#include <utility>
#include <map>
#include <algorithm>
#include <set>


using namespace std;

int testCase;
int N;
set< pair<int, int> > nerd;

int main()
{
    int tmp, tmpp;
    cin>>testCase;
    for(int i = 0; i < testCase; i++)
    {
        cin>>N;
        for(int j = 0; j < N; j++)
        {
            cin>>tmp>>tmpp;
            nerd.insert(make_pair(tmp, tmpp));
        }
    }
}
