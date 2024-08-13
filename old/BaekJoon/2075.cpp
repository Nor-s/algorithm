#include <iostream>
#include <set>

using namespace std;

set<int> s;

int main() {
    int n, tmp; 
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &tmp);
            if(s.size() >= n && *s.begin() < tmp) {
                s.erase(s.begin());
                s.insert(tmp);
            } else if(s.size() < n){
                s.insert(tmp);
            }
        }
    }
    printf("%d", *s.begin());
}