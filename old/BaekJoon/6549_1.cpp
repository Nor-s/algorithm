#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

ll n;
vector<ll> h;

ll sol1(ll left, ll right) {
    ll mid = (left + right)/2;
    ll midArea = h[mid], height = h[mid];
    ll l = mid - 1, r = mid + 1;

    if(left +1 >= right) {
        return midArea; 
    }
    while(l > left || r < right) {
        if(l <= left || (r < right && h[l] <= h[r])) {
            height = min(h[r], height);
            r++;
        }
        else {
            height = min(height, h[l]);
            l--;
        }
        ll width = r -1 - l; 
        midArea = max(midArea, width * height);
    }
    return max(midArea, max(sol1(left, mid), sol1(mid, right)));
}

int main() {
    while(true) {
       cin>>n;
       if(n == 0) {
           break;
       }
       h = vector<ll>(n+2);
       h[0] = h[n+1] = 0;
       for(int i = 1; i <= n; i++) {
           cin>>h[i];
       }
       cout<<sol1(0, n+1)<<"\n";
    }
}