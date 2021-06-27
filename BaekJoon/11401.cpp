#include <iostream>

using namespace std;
long long N, K;
long long p = 1000000007;

long long fact(long long n) {
    long long ret = 1;
    for(int i = 2; i <= n; i++) {
        ret = (i*ret)%p;
    }
    return ret;
}
long long powll(long long n, long long k) {
    if(k == 1) {
        return n;
    }
    if(k%2 == 0) {
        long long t =  powll(n, k / 2);
        return (t * t) % p;
    }
    else {
        return (powll(n, k - 1) * n) % p;
    }
}
long long solve(long long n, long long k) {
    return (fact(n) * powll((fact(k) * fact(n-k)) % p, p - 2)) % p;
}

//gcd(a, b) = bx + ay
// b * xy.first + a * xy.second
long long gcd(long long a, long long b, pair<long long, long long>& xy) {
    if(a == 0) { 
        xy.first = 0;
        xy.second = 1;
        return b;
    }
    int ret = gcd(b % a, a, xy);

    if(b % a != 0) {
        long long f = xy.first;
        xy.first = xy.second;
        xy.second = xy.second * (-b / a) + f;
    }
    
    return ret;
}

long long solve1(long long n, long long k) {
    pair<long long, long long> xy;
    long long x = gcd((fact(n - k) * fact(k))%p, p, xy);

    return (fact(n) * (xy.second + p)%p)% p;
}

int main() {
    cin>>N>>K;
    //cout<<solve(N, K)<<"\n";
    cout<<solve1(N, K);
}