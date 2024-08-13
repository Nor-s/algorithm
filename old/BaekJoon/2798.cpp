#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <set>
#include <numeric>
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL));
    int n = 0;
    int m = 0;
    vector<int> v;
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int max = 0;
    for(int i = 0; i < 100111; i++) {
        set<int> s;
        while(s.size() != 3) {
            s.insert(v[rand()%v.size()]);
        }
        int sum = accumulate(s.begin(), s.end(), 0);
        if(sum > max && sum <= m)
            max = sum;
    }
    cout<<max<<"\n";
}