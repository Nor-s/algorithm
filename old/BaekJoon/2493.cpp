#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;


int main() {
    int N;
    cin>>N;
    vector<int> s(N+1);
    vector<pair<int, int> > s1;
    vector<int> answer(N, 0);
    s[0] = INT32_MAX;

    for(int i = 0 ; i < N; i++) {
        scanf("%d", &s[i+1]);
    }

    for(int i = N; i >= 0 ; i--) {
        while(!s1.empty() && s1.back().first <= s[i]) {
            answer[s1.back().second - 1] = i;
            s1.pop_back();
        }
        s1.push_back(make_pair(s[i], i));
    }

    for(int i = 0; i < N ; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");

}