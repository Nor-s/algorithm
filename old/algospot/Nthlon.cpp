#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int m;
vector<pair<int, int> > event;
int main()
{

    int C;
    cin>>C;
    while(C--)
    {
        cin>>m;
        event.clear();

        while(m--)
        {
            int a, b;
            cin>>a>>b;
            event.push_back(make_pair(a, b));
        }

        
    }
}