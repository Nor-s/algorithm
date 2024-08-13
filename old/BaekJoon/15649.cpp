#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVector(vector<int>& v) {
    for(int i = 0 ; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

void back(int n, int m, vector<int>& s, vector<bool>& numbers) {
    if(s.size() == m) {
        printVector(s);
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(numbers[i]) continue;
        numbers[i] = true;
        s.push_back(i);
        back(n, m, s, numbers);
        s.pop_back();
        numbers[i] = false;
    }
}

int main() {
    int n = 0; 
    int m = 0;
    vector<int> s;
    vector<bool> numbers(n+1, false);
    cin>>n>>m;
    back(n , m, s, numbers);
}