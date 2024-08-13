#include <bits/stdc++.h>

using namespace std;
long long n;
 
long long factorSimple()
{
    long long ret = n;
    long long sqrtn = sqrt(n);
    for (long long div = 2; div <= sqrtn; div++) {
        if(n%div == 0) {
            ret = ret / div * (div - 1);
        }
        while(n%div==0) {
            n /= div;
        }
        
    }
    if(n != 1) { 
        ret = ret / n * (n-1);
    }
    return ret;
}

int main() {
    cin>>n;
    long long  answer = factorSimple();
    cout<<answer;
}