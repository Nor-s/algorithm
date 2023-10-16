#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//08 16

struct RMQ {
    vector<pair<int, int> > segment;
    RMQ(vector<pair<int, int> >& v) {
        segment.resize(v.size()*4+4);
        init(v, 1, 0, segment.size());
        for(int i = 0; i < v.size(); i++ ) {
            cout<<" <"<<v[i].first<<" , "<<v[i].second<<"> ";
        }
        cout<<"\n";
    }
    pair<int, int> init(vector<pair<int, int> >& v, int idx, int lo, int hi) {
        if(lo+1==hi) {
            if(v[lo].second == -1) {
                return segment[idx] = {INT32_MAX, INT32_MIN};
            }
            return segment[idx] = {v[lo].second, v[lo].second};
        }
        int mid = (lo+hi)/2;
        pair<int, int> left = init(v, idx*2, lo, mid);
        pair<int, int> right = init(v, idx*2+1, mid, hi);
        int mincost = min(left.first, right.first);
        int maxcost = max(right.second, left.second);
        segment[idx] =  {mincost, maxcost};
        return segment[idx];
    }
    pair<int, int> query(vector<pair<int, int> >& v, int a, int b) {
        return query(v, 1, 0, segment.size(), a, b);
    }
    pair<int, int> query(vector<pair<int, int> >& v, int idx, int lo, int hi, int a, int b) {
        if(lo + 1 == hi) {
            if(a < v[lo].first) {
                return {INT32_MAX, INT32_MIN};
            }
            return segment[idx];
        }
        int mid = (lo+hi)/2;
        if(b < mid) {
            return query(v, idx*2, lo, mid, a, b);
        }
        if(a > mid) {
            return query(v, idx*2+1, mid, hi, a, b);
        }
        else {
            pair<int, int> left = query(v, idx*2, lo, mid, a, mid);
            pair<int, int> right = query(v, idx*2+1, mid, hi, mid, b);
            int mincost = min(left.first, right.first);
            int maxcost = max(right.second, left.second);
            return {mincost, maxcost};
        }
    }

};

vector<vector<pair<int, int>>> adjList;
vector<int> travelpos;
vector<pair<int, int> > travel;
vector<int> newseq;
vector<int> newseq2origin;
int newnum = 0;
    int n;


void dfs(int here, int parent) {
    newseq[here] = newnum;
    newseq2origin[newseq[here]] = here;
    newnum++;
    
    travel.push_back({newseq[here], -1});
    travelpos[newseq[here]] = travel.size()-1;

    for(auto there : adjList[here]) {
        if(there.first != parent) {
            travel.push_back({newnum, there.second});
            dfs(there.first, here);
            travel.push_back({newseq[here], there.second});
        }
    }
}

void init() {
    newseq = vector<int>(n, -1);
    travelpos = vector<int>(n, -1);
    newseq2origin = vector<int>(n, -1);
    dfs(0, -1);
}

pair<int, int> LCA(RMQ& r, int a, int b) {
    int newa = travelpos[newseq[a]];
    int newb = travelpos[newseq[b]];
    if(newa > newb) {
        swap(newa, newb);
    }
    return r.query(travel, newa, newb);
}

int main()
{
    cin >> n;
    adjList = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        adjList[a-1].push_back({b-1, w});
        adjList[b-1].push_back({a-1, w});
    }
    init();
    RMQ rmq(travel);
    int q;
    cin>>q;
    for(int i = 0; i < q; i++) {
        int a, b;
        cin>>a>>b;
        pair<int, int> answer = LCA(rmq,a-1,b-1);
        cout<<answer.first<<" "<<answer.second<<"\n";
    }
}