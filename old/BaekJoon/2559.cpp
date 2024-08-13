#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, c;
    cin>>n>>c;
    vector<int> v(n);
    int size =0;
    int sum = 0, answer = -1e9;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        if(size < c) {
            size++;
            sum += v[i];
        }
    }
    answer = sum;
    for(int j = c; j < n; j++) {
        sum += v[j];
        sum -= v[j - c];
        answer = max(sum, answer);
    }
    cout<<answer;
}
