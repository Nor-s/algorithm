#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <map>

using namespace std;
int N;

class State
{

public:
    unsigned long long top[4];
    int ring;

    State(){}
    State(const State& s) {
        for(int i = 0; i < 4; i++)
            this->top[i] = s.top[i];
        this->ring = s.ring;
    }
    State(vector<vector<int> >& r) {
        ring = (1<<(N*2));

        for(int i = 0; i < r.size(); i++) 
        {
            top[i] = 15<<4;
            for(int j = 0; j < r[i].size(); j++)
            {
                ring |= (i<<(2*(r[i][j]-1)));
                pushTop(i, r[i][j]);
            }
        }
    }
    void pushTop(int i, int num)
    {
        int size = sizeTop(i)+1;
        top[i] = ((top[i]>>4)<<4);
        top[i] |= (unsigned long long)num;
        top[i] = (top[i]<<4);
        top[i] |= size;
    }
    void popTop(int i)
    {
        int size = sizeTop(i) - 1;
        if(getTop(i) == 15) return;
        top[i] = (top[i]>>8);
        top[i] = (top[i]<<4);
        top[i] |= size;
    }
    int getTop(int i)
    {
        return ((top[i]>>4) & ((1ul<<4) - 1));
    }
    int sizeTop(int i)
    {
        return top[i] & ((1ul<<4) - 1);
    }
    void moveRing(int ringNum, int pos, int beforePos) {
        ring &= ~(3<<(2*(ringNum-1)));
        ring |= (pos<<(2*(ringNum-1)));
        pushTop(pos, ringNum);
        popTop(beforePos);
    }
    vector<State> getAdjacent(){
        vector<State> adj;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(getTop(i) < getTop(j))
                {
                    moveRing(getTop(i), j, i);
                    adj.push_back(*this);
                    moveRing(getTop(j), i, j);
                }
            }
        }
        return adj;
    }

    bool operator < (const State& rhs) const{
        return this->ring < rhs.ring;
    }
    bool operator == (const State& rhs) const {
        return this->ring == rhs.ring;
    }
    int estimate()
    {
        return sizeTop(0) + sizeTop(1) + sizeTop(2);
    }
};


int minMove(State start, State finish)
{
    if(start == finish) return 0;
    map<State, int> d;
    
    queue<State> q;
    q.push(start);
    d[start] = 0;
    
    while(!q.empty())
    {
        State here = q.front();
        q.pop();
        int cost = d[here];

        vector<State> adjList = here.getAdjacent();
        for(int i = 0; i < adjList.size(); i++)
        {
            if(d.count(adjList[i]) == 0)
            {
                if(adjList[i] == finish) return cost + 1;
                d[adjList[i]] = cost + 1;
                q.push(adjList[i]);
            }
        }
    }
    return -1;
}

int sgn(int i)
{
    if(i == 0) return 0;
    return (i > 0 ? 1 : -1);
}

int minMove1(State start, State finish)
{
    if(start == finish) return 0;
    map<State, int> d;

    queue<State> q;
    q.push(start);
    q.push(finish);
    d[start] = 1;
    d[finish] = -1;

    while(!q.empty())
    {
        State here = q.front();
        q.pop();
        int count = d[here];
        vector<State> adjList = here.getAdjacent();
        for(int i = 0; i < adjList.size(); i++)
        {
            map<State, int>::iterator mi = d.find(adjList[i]);
            
            if(mi == d.end())
            {
                q.push(adjList[i]);
                d[adjList[i]] = count + sgn(count);
            }
            else if(sgn(d[adjList[i]])*-1 == sgn(count)){
                return abs(d[adjList[i]]) + abs(count) - 1; 
            }
        }
    }
    return -1;
}

void dfs(State here, const State& finish, int steps, int& best)
{
    cout<<steps<<"\n";
    if(steps + here.estimate() >= best) return;
    if(finish == here) {best = steps; return;}
    vector<State> adjList = here.getAdjacent();
    for(int i = 0; i < adjList.size(); i++) 
            dfs(adjList[i], finish, steps + 1, best);
}
int minMove2(State start, State finish)
{
    int best;
    for(int limit = 5; ;limit+=5)
    {
        best = limit + 1;
        dfs(start, finish, 0, best);
        if(best <= limit) return best;
    }
    return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<vector<int> > input = vector<vector<int> >(4);
        cin>>N;
        for(int i = 0; i < 4; i++)
        {
            int vn;
            cin>>vn;
            while(vn--)
            {
                int tmp;
                cin>>tmp;
                input[i].push_back(tmp);
            }
        }
        vector<vector<int> > target = vector<vector<int> >(4);
        for(int i = N; i >= 1; i--)
            target[3].push_back(i);
       cout<<minMove2(State(input), State(target))<<"\n";
    }
    return 1;
}