#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int MAX = 30*500;
bool cache[2*MAX + 1][31];

void initialize(vector<int>& weight, int idx, int w) {

    if(cache[w + MAX][idx]) {
        return;
    }
    
    cache[w + MAX][idx] = true;
    if(idx == weight.size())
        return;
    
    initialize(weight, idx+1,  w - weight[idx]);
    initialize(weight, idx+1,  w);
    initialize(weight, idx+1,  w + weight[idx]);
}

int main() {
    int n, m;
    cin>>n;

    vector<int> weight(n);
    for(int i = 0; i < n ; i++) {
        cin>>weight[i];
    }
    initialize(weight, 0, 0);

    cin>>m;
    
    for(int i = 0; i < m; i++) {
        int marble;
        cin>>marble;
        if(marble > MAX) {
            cout<<"N ";
        }
        else if(cache[marble + MAX][weight.size()]) {
            cout<<"Y ";    
        }
        else {
            cout<<"N ";
        }
    }
    cout<<"\n";
}