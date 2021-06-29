#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

int one(int a);
int two(int a);
int three(int a);

int (*p[])(int a) = {one, two, three};

int cache[1000001];
int choice[1000001];
int MAX = 2000;

int toOne(int N) {
    if(N == 0) {
        return MAX;
    }
    if(N==1) {
        return 0;
    }
    if(cache[N]!= -1) {
        return cache[N];
    }
    cache[N] = MAX;
    for(int i = 2; i >= 0; i--) {
        int next = toOne((*p[i])(N)) + 1;
        if(cache[N] > next) {
            cache[N] = next;
            choice[N] = i;
        }
    }
    return cache[N];
}
void print(int N) {
    cout<<N<<" ";
    if(N == 1) {
        return;
    }
    return print((*p[choice[N]])(N));
}

int main() {
    int N;
    cin >> N;
    memset(cache, -1, sizeof cache);
    memset(choice, -1, sizeof choice);
    cout<<toOne(N)<<"\n";
    print(N);
}
int one(int a) {
    if(a%3 == 0) {
        return a/3;
    }
    return a;
}
int two(int a) {
    if(a%2 == 0) {
        return a/2;
    }
    return a;
}
int three(int a) {
    return a - 1;
}