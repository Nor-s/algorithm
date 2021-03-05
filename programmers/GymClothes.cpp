#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int networkflow(int src, int sink, vector<vector<int> >& capa)
{
    int ret = 0, V = capa.size();
    vector<vector<int> > flow(V, vector<int>(V, 0));
    
    while(true)
    {
        vector<int> parent(V, -1);
        queue<int> q;
        parent[src] = src;
        q.push(src);
        while(!q.empty()&& parent[sink] == -1)
        {
            int here = q.front(); q.pop();
            for(int there = 0; there < V; there++)
                if(parent[there] == -1 && capa[here][there] - flow[here][there]>0)
                {
                    q.push(there);
                    parent[there] = here;
                }
        }
        if(parent[sink] == -1) break;
        for(int p = sink; p != src; p = parent[p])
            flow[parent[p]][p] += 1;
        ret += 1;
    }
    return ret;
}
int solution1(int n, vector<int>& lost, vector<int>& reserve)
{
    vector<vector<int> > capa = vector<vector<int> >(n+2, vector<int>(n+2, 0));
    int lostStudent = 0;
    for(int i = 0; i < reserve.size(); i++)
            capa[0][reserve[i]] = 1;
    
    for(int i = 0; i < lost.size(); i++)
        if(capa[0][lost[i]] != 1)
        {
            lostStudent++;
            capa[lost[i]][n+1] = 1;
        }
        else
            capa[0][lost[i]] = 0;
        
    for(int i = 0; i < reserve.size(); i++)
    {
        if(reserve[i]-1 < n-1 && capa[0][reserve[i]] == 1)
        	capa[reserve[i]][reserve[i]+1] = 1;
        if(reserve[i]-1 > 0 && capa[0][reserve[i]] == 1)
        	capa[reserve[i]][reserve[i]-1] = 1;
    }
    return networkflow(0, n+1, capa) + n - lostStudent;
}
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> student(n, 0);
    for(int i = 0 ; i < lost.size() ; i++)
        student[lost[i]-1]--;
    for(int i = 0; i < reserve.size(); i++)
        student[reserve[i]-1]++;
    for(int i = 0; i < n; i++)
        if(student[i] < 0)
        {
            if(0 < i && student[i-1] > 0)
                student[i-1]--;
            else if(i < n-1 && student[i+1] > 0)
                student[i+1]--;
            else 
               answer--;
        }
    return answer;
}

int main()
{
    vector<int> a = {2, 4};
    vector<int> b = {1, 3, 5};
    cout<<solution(5, a, b)<<"\n";
    vector<int> c = {2, 4};
    vector<int> d = {3};
    cout<<solution(5, c, d)<<"\n";
    vector<int> e = {3};
    vector<int> f = {1};
    cout<<solution(3, e, f)<<"\n";
    vector<int> Lost = {10,16,19,20,24,26,27};
    vector<int> Reserve = {4,7,8,10,13,14,16,17,18,19,21,22,23,24,25,26,27};
    cout<<solution(30, Lost, Reserve)<<"\n";
    vector<int> aa = {2, 3, 4};
    vector<int> bb = {1, 2, 3};
    cout<<solution(5, aa, bb)<<"\n";
    vector<int> aaa = {1, 2, 3};
    vector<int> bbb = {2, 3, 4};
    cout<<solution(5, aaa, bbb)<<"\n";
}