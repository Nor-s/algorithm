#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define DUMMY 123456

// cached[i] : center i -> maximum radius
// 펠린드룸은 중심에서 대칭
// 짝수인 경우를 대비해 중간에 임의의 더미 값을 넣어줘야한다.
int cached[4001];

void initial(vector<int>& s) {
    int N = s.size(), r = 0, p = 0;
    memset(cached, 0, sizeof cached);
    for(int i = 0; i < N ; i++) {
        if(i <= r) {
            cached[i] = min(cached[2*p-i], r - i);
        }
        while(i - cached[i] - 1 >= 0 && i + cached[i] + 1 < N && s[i - cached[i] - 1] == s[i + cached[i] + 1])  {
            cached[i]++;
        }
        if(r < i + cached[i]) {
            r = i + cached[i];
            p = i;
        }
    }
}

bool isPalindrome(int a, int b) {
    int radius = (b*2 - a*2) / 2;
    int center = b*2 - radius;
    //cout<<"\n\nc : "<< center<<" "<<cached[center]<<"\n\n";
    return radius <= cached[center];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<int> s;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        s.push_back(tmp);
        if(i != n-1) {
            s.push_back(DUMMY);
        }
    }
    initial(s);

    int m;
    cin>>m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin>>a>>b;
        cout<<isPalindrome(a - 1, b - 1)<<"\n";
    }
}