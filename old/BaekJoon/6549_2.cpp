#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define ll long long

using namespace std;

ll n;
vector<ll> h;

ll sol1() {
    stack<ll> s; 
    ll ret = 0;
    for(ll i = 1; i <= n+1; i++) {
        while(!s.empty() && h[s.top()] >= h[i]) {
            int tmp = s.top(); s.pop();
            int width = i - ((s.empty())? 0 : s.top()) - 1;
            ret = max(ret, h[tmp]*width );
        }
        s.push(i);
    }
    return ret;
}

int main() {
    while(true) {
       cin>>n;
       if(n == 0) {
           break;
       }
       h = vector<ll>(n+2);
       h[0] = h[n+1] = 0;
       for(ll i = 1; i <= n; i++) {
           cin>>h[i];
       }
       cout<<sol1()<<"\n";
    }
}