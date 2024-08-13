#include <iostream>

using namespace std;

long long countn(long long a, long long n){
    long long ret = 0;
    for(long long i = n; i <= a; i *= n) {
        ret += a/i;
    }
    return ret;
}

int main() {
    long long n, m;
    cin>>n>>m;
    long long total2 =  countn(n, 2) - (countn(m, 2) + countn(n - m, 2)); 
    long long total5 =  countn(n, 5) - (countn(m, 5) + countn(n - m, 5)); 
    cout<<min(total2, total5);
}