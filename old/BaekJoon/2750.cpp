#include <map>
#include <iostream>

using namespace std;

int main() {
    int n = 0;
    map<int, int> m;  
    cin>>n;
    for(int i = 0; i < n ; i++) {
        int tmp = 0;
        cin>>tmp;
        m[tmp]++;
    }
    for(auto it = m.begin(); it != m.end(); it++) {
        for(int i = 0; i < it->second; i++) {
            std::cout<<it->first<<"\n";
        }
    }
}