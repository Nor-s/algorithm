#include <bits/stdc++.h>

using namespace std;

struct RMQ {
    int n;
    vector<int> rangeMin;
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n*4);
        init(array, 0, n-1, 1);
    }
    int init(const vector<int>& array, int left, int right, int node) {
        if(left == right)
            return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node*2);
        int rightMin = init(array, mid + 1, right, node*2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if( right < nodeLeft || nodeRight < left) return INT32_MAX;
        if( left <= nodeLeft && nodeRight <= right) return rangeMin[node];
        int mid = (nodeLeft + nodeRight)/2;
        return min(query(left, right, node*2, nodeLeft, mid),
                   query(left, right, node*2+1, mid+1, nodeRight));
     }
    int query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
};

const int MAX_N = 40001;
//tree number <-> new number serial
int no2serial[MAX_N], serial2no[MAX_N];
// first visit location, 
int locInTrip[MAX_N], depth[MAX_N];
int nextSerial;
int N;
int M;
vector<vector<pair<int, int> > > child;

void traverse(int here, int parent, int d, vector<int>& trip) {
    no2serial[here] = nextSerial;
    serial2no[nextSerial] = here;
    ++nextSerial;
 
    depth[here] = d;
    locInTrip[here] = trip.size();
    trip.push_back(no2serial[here]);
    
    for(int i = 0; i < child[here].size(); ++i) {
        int there = child[here][i].first;
        int dist = child[here][i].second;
        if(parent == there) {
            continue;
        }
        traverse(there, here, d + dist, trip);
        trip.push_back(no2serial[here]);
    }
}
RMQ* prepareRMQ(int root) {
    nextSerial = 0;
    vector<int> trip;
    traverse(root, root, 0, trip);
    return new RMQ(trip);
}
 
int distance(RMQ* rmq, int u, int v) {
    int lu = locInTrip[u], lv = locInTrip[v];
    if(lu > lv) swap(lu, lv);
    int lca = serial2no[rmq->query(lu, lv)];
    return depth[u] + depth[v] - 2*depth[lca];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    child = vector<vector<pair<int, int> > >(N+1);
    int root = 1;
    for(int i = 0; i < N - 1; i++) {
        int a, b, d;
        cin>>a>>b>>d;
        child[a].push_back({b, d});
        child[b].push_back({a, d});
        if(child[root].size() < child[a].size()){
            root = a;
        }
        if(child[root].size() < child[b].size()) {
            root = b;
        }
    }
    RMQ* rmq = prepareRMQ(root);
    cin>>M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin>>a>>b;
        if(a == b) {
            cout<<0<<"\n";
        }
        else {
            cout<<distance(rmq, a, b)<<"\n";
        }
    }
}